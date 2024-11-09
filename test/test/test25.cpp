#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
ListNode* reverseKGroup(ListNode* head, int k)
{
    // 递归解法   每次反转K个，  之后链接到后面
    if (head == nullptr || k == 1)
        return head;
    // 首先判断判断是否有k个，否则不进行反转
    int n = 0;
    ListNode* p = head;
    while (p != nullptr && n < k)
    {
        n++;
        p = p->next;
    }
    if (n < k)
        return head;
    ListNode newhead(0, nullptr);
    p = head;
    // 存在K个值，可以进行反转
    ListNode* pre=head; // 记录前一个节点
    for (int i = 0; i < k; i++)
    {
        pre=p->next;
        p->next = newhead.next;
        newhead.next = p;
        p = pre;

    }
    head->next = reverseKGroup(pre->next, k);
    return newhead.next;
}
int main()
{
    ListNode* head = new ListNode(1, nullptr);
    ListNode* p = head;
    for (int i = 2; i <= 5; i++)
    {
        ListNode* temp = new ListNode(i, nullptr);
        p->next = temp;
        p = p->next;
    }
    reverseKGroup(head, 2);



}