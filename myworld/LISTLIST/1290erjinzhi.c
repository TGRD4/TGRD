/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head)
{
    int sum=0;
    struct ListNode*p=head;
    while(p)
    {
        sum*=2;
        sum+=p->val;
    }
    return sum;
}