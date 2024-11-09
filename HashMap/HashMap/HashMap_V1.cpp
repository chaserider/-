#ifndef _UNORDERED_MAP1
#define _UNORDERED_MAP1


#include <iostream>
#include <assert.h>
#include <vector>

template<typename key_t, typename val_t, typename hash_t = std::hash<key_t>>
	struct node {//单个节点
		key_t key;
		val_t val;
		node* next;
		node() :key(0), val(0), next(nullptr) {}
		node(key_t key, val_t val) :key(key), val(val), next(nullptr) {}
	};
const float factor = 0.75f;//装载因子

template<typename key_t, typename val_t, typename hash_t = std::hash<key_t>>
	class unordered_map {
		//数据定义
	public:
		size_t cnt;//已经插入的键值对数目
		size_t capacity;//当前最大容量
		node<key_t, val_t>** map;//一条哈希链的首地址
		const float factor = 0.75f;//装载因子

		//构造函数
	public:
		//默认构造函数
		unordered_map() :cnt(0), capacity(64), map(nullptr)//默认cap长度设置位16
		{
			map = new node<key_t,val_t> * [capacity];
			for (int i = 0; i < capacity; i++)
			{
				map[i] = nullptr;
			}
		}
		unordered_map(size_t capacity) :cnt(0), capacity(capacity), map(nullptr)//默认cap长度设置位16
		{
			map = new node<key_t,val_t> * [capacity];
			for (int i = 0; i < capacity; i++)
			{
				map[i] = nullptr;
			}
		}
		//复制构造函数
		unordered_map(unordered_map& src) :cnt(src.cnt), capacity(src.capacity), map(src.map) {
			assert(capacity > 0 && map != nullptr);
			src.map = nullptr;//已经成功转移内存，将原来的src的map设置位nullptr防止析构函数销毁内存
		}
		~unordered_map() { delete[]map; }

		//根据散列函数得到地址
		size_t getIndex(key_t key)
		{
			hash_t to_hash;
			size_t code = to_hash(key);//用于对应哈希仿函数得到的hashcode
			code = code ^ (code >> 16);//扰动函数
			return code & (capacity - 1);//子掩码方式得出下标

		}
		//put方法
	public:
		void resize() {
			capacity << 1;//扩容两倍
			node<key_t,val_t>** tmp = map;//缓存原桶数组
			map = new node <key_t, val_t>* [capacity];//构造新的桶数组
			std::fill(map, map + capacity, nullptr);
			rehash(tmp);
			delete[]tmp;//删除原桶数组
		};//扩容
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
				map[index] = node;//头插
			}
		}
		//重新对桶数组赋予地址
		void rehash(node<key_t, val_t>** preTable)
		{
			cnt = 0;//由于insert会重新把size计数的
			assert(preTable != nullptr);//断言非空
			size_t preSize = capacity >> 1;//扩容前的容量
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
			if (cnt >= capacity * factor) resize();//如果超过装入量，对桶进行扩容
			putVal(key, val);//继续装入键值对
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
			//如果这条链不存在对应的key就直接头插
			node<key_t, val_t>* p = new node(key, val);
			p->next = map[index];
			map[index] = p;
			cnt++;

			//三种插入方式，首先有一条桶数组链，首先查找对应索引如果索引没有值则填入，如果有值则放入该链表后，如果不存在该索引地址，则创建一个进行头插
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