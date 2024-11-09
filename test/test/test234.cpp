#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
bool isPalindrome(ListNode* head)
{
	// 利用额外辅助空间进行判断

	ListNode* newhead = new ListNode(0, nullptr);
	ListNode* p = head;
	while (p != nullptr)
	{
		ListNode temp(p->val,newhead->next);
		newhead->next = &temp;
		p = p->next;
	}
	newhead = newhead->next;
	p = head;
	while (newhead != nullptr)
	{
		if (newhead->val != p->val)
		{
			return false;
		}
		newhead = newhead->next;
		p = p->next;
	}
	
	return true;
}
int main()
{
	ListNode temp(1);
	ListNode temp1(2);
	ListNode temp2(2);
	ListNode temp3(1);
	temp.next = &temp1;
	temp1.next = &temp2;
	temp2.next = &temp3;
	isPalindrome(&temp);

}