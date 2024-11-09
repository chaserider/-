#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* reverse(ListNode* head)
{
	if (head->next == nullptr)
		return head;
	else
	{
		ListNode* newhead = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newhead;
	}
}
ListNode* reverseList(ListNode* head)
{
	// ตÝน้
	if (head == nullptr)
		return nullptr;
	else
	{
		ListNode* newhead = new ListNode(0, head);
		newhead=reverse(newhead->next);
		return newhead;
	}
}

int main()
{
	ListNode* head = new ListNode(1, nullptr);
	ListNode* p = head;
	for (int i = 2; i <5; i++)
	{
		ListNode* temp = new ListNode(i, nullptr);
		p->next = temp;
		p = p->next;
	}

	ListNode *it=reverseList(head);
	while (it != nullptr)
	{
		std::cout << it->val << std::endl;
		it = it->next;
	}
	std::cin.get();
}