#include <iostream>
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rempbeNthFromEnd(ListNode* head, int n)
{
	ListNode* tmp = new ListNode(0, head);
	ListNode* fast = head;
	ListNode* slow = tmp;
	while (n > 0)
	{
		fast = fast->next;
		n--;
	}
	while (fast != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	head = tmp->next;
	delete tmp;
	return head;
}

int main()
{
	
}