/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* p=head;
    int cnt=0;
    while(p)
    {
        p=p->next;
        cnt++;//计算链表总长度
    }
    p=head;//重置p指向head
    for(int i=0;i,i<cnt/2;i++)
        p=p->next;//找寻链表中点
    return p;
}