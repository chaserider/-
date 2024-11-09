//µ¥Á´±í

template<typename value>
struct Node
{
	value val;
	node* next;
	node() :val(0), next(nulllptr);
};

template<typename value>
class LinkList
{
public:
	node<value>* head;
	int size;
	LinkList() :size(0) { head = new node<value>(); };
	LinkList(node<value>* node, int s) :head(node), size(s);
};