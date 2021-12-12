struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *L1,*L2;
    L1=headA;
    L2=headB;
    while(L1!=L2)
    {
        L1=((L1==NULL)?headB:L1->next);
        L2=((L2==NULL)?headA:L2->next);//若不存在相交结点则返回NULL
    }
    return L2;//返回相交位置
}
