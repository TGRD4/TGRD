struct ListNode 
{
    int val;
    struct ListNode *next;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* p1 = l1, * p2 = l2; 
    struct ListNode* k = p3;//新插入结点
    while(p1 && p2)
    {
        if((p1 -> val) <= ( p2 -> val))//p1->next小则先插入p1->next
        {
            k -> next = p1;
            k = p1;
            p1 = p1 -> next;
        }
        else
        {  
            k -> next = p2;
            k = p2; 
            p2 = p2->next;
        }
    }
    if(p1==NULL)
        k -> next = p2 ; 
    else if(p2==NULL)
        k -> next = p1; 
    return p3->next;
}
