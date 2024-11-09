#ifndef _UNORDERED_MAP1
#define _UNORDERED_MAP1


#include <iostream>
#include <assert.h>
#include <vector>

template<typename key_t, typename val_t, typename hash_t = std::hash<key_t>>
	struct node {//�����ڵ�
		key_t key;
		val_t val;
		node* next;
		node() :key(0), val(0), next(nullptr) {}
		node(key_t key, val_t val) :key(key), val(val), next(nullptr) {}
	};
const float factor = 0.75f;//װ������

template<typename key_t, typename val_t, typename hash_t = std::hash<key_t>>
	class unordered_map {
		//���ݶ���
	public:
		size_t cnt;//�Ѿ�����ļ�ֵ����Ŀ
		size_t capacity;//��ǰ�������
		node<key_t, val_t>** map;//һ����ϣ�����׵�ַ
		const float factor = 0.75f;//װ������

		//���캯��
	public:
		//Ĭ�Ϲ��캯��
		unordered_map() :cnt(0), capacity(64), map(nullptr)//Ĭ��cap��������λ16
		{
			map = new node<key_t,val_t> * [capacity];
			for (int i = 0; i < capacity; i++)
			{
				map[i] = nullptr;
			}
		}
		unordered_map(size_t capacity) :cnt(0), capacity(capacity), map(nullptr)//Ĭ��cap��������λ16
		{
			map = new node<key_t,val_t> * [capacity];
			for (int i = 0; i < capacity; i++)
			{
				map[i] = nullptr;
			}
		}
		//���ƹ��캯��
		unordered_map(unordered_map& src) :cnt(src.cnt), capacity(src.capacity), map(src.map) {
			assert(capacity > 0 && map != nullptr);
			src.map = nullptr;//�Ѿ��ɹ�ת���ڴ棬��ԭ����src��map����λnullptr��ֹ�������������ڴ�
		}
		~unordered_map() { delete[]map; }

		//����ɢ�к����õ���ַ
		size_t getIndex(key_t key)
		{
			hash_t to_hash;
			size_t code = to_hash(key);//���ڶ�Ӧ��ϣ�º����õ���hashcode
			code = code ^ (code >> 16);//�Ŷ�����
			return code & (capacity - 1);//�����뷽ʽ�ó��±�

		}
		//put����
	public:
		void resize() {
			capacity << 1;//��������
			node<key_t,val_t>** tmp = map;//����ԭͰ����
			map = new node <key_t, val_t>* [capacity];//�����µ�Ͱ����
			std::fill(map, map + capacity, nullptr);
			rehash(tmp);
			delete[]tmp;//ɾ��ԭͰ����
		};//����
		void insert(node<key_t, val_t>* node)
		{
			assert(map != nullptr && node != nullptr);
			size_t index = getIndex(node->key);
			if (map[index] == nullptr)
			{
				node->next = nullptr;
				map[index] = node;
			}
			else
			{
				node->next = map[index];
				map[index] = node;//ͷ��
			}
		}
		//���¶�Ͱ���鸳���ַ
		void rehash(node<key_t, val_t>** preTable)
		{
			cnt = 0;//����insert�����°�size������
			assert(preTable != nullptr);//���Էǿ�
			size_t preSize = capacity >> 1;//����ǰ������
			for (size_t i = 0; i < preSize; i++)
			{
				if (preTable[i] != nullptr)
				{
					node<key_t, val_t>* preNode;
					node<key_t, val_t>* curNode = preTable[i];
					while (curNode != nullptr)
					{
						preNode = curNode;
						curNode = curNode->next;
						insert(preNode);
					}
				}
			}
		}

		void put(key_t key, val_t val)
		{
			if (cnt >= capacity * factor) resize();//�������װ��������Ͱ��������
			putVal(key, val);//����װ���ֵ��
		}
		void putVal(key_t key, val_t val)
		{
			size_t index = getIndex(key);
			node<key_t, val_t>* tmp = map[index];
			if (tmp == nullptr) {
				map[index] = new node(key, val);
				cnt++;
				return;
			}
			//��������������ڶ�Ӧ��key��ֱ��ͷ��
			node<key_t, val_t>* p = new node(key, val);
			p->next = map[index];
			map[index] = p;
			cnt++;

			//���ֲ��뷽ʽ��������һ��Ͱ�����������Ȳ��Ҷ�Ӧ�����������û��ֵ�����룬�����ֵ�������������������ڸ�������ַ���򴴽�һ������ͷ��
		}

		std::vector<val_t> get(key_t key)
		{
			std::vector<val_t> ret = getVal(key);
			return ret;
		}
		bool find(key_t key)
		{
			return getVal(key) != nullptr;
		}

	/*	val_t& operator[](key_t key)
		{
			val_t* val = getval(key);
			return *val;
		}*/


	private:
		val_t getVal(key_t key)
		{
			size_t index = getIndex(key);
			node<key_t, val_t>* p = map[index];
			while (p != nullptr)
			{
				if (p->key != key)
					p = p->next;
				else
				{
						return p;
				}

			}
			return p;
		}
	};



#endif // !_UNORDERED_MAP