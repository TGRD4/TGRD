struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(!head)
        return head;
    struct ListNode* p = head;
    while(p->next)
    {
        if(p->val==p->next->val)
            p=p->next;
        p=p->next;//相当于只赋值了一次
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head) 
        return head;
    struct ListNode* cur = head;
    while (cur->next)
    {
        if (cur->val == cur->next->val)
            cur->next = cur->next->next;//正确
        else cur = cur->next;
    }
    return head;
}