/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteNode(struct ListNode* head, int val)
{
    if(!head) return head;
    struct ListNode*p=head;
    if (p->val == val)//若删除了头结点
        return p->next;//返回首元结点
    while(p)
    {
        if(p->next->val==val)//若下一个是要删除的结点
        {
            p->next=p->next->next;//跳过下一个结点
            break;
        }
        p=p->next;
    }
    return head;
}