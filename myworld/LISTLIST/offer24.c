/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else
    {
        struct ListNode *newhead = reverseList(head->next);//递归反转链表
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
}
