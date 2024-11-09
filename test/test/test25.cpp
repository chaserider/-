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
    // �ݹ�ⷨ   ÿ�η�תK����  ֮�����ӵ�����
    if (head == nullptr || k == 1)
        return head;
    // �����ж��ж��Ƿ���k�������򲻽��з�ת
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
    // ����K��ֵ�����Խ��з�ת
    ListNode* pre=head; // ��¼ǰһ���ڵ�
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