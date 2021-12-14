struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *L1,*L2;
    L1=headA;
    L2=headB;
    while(L1!=L2)
    {
        L1=((L1==NULL)?headB:L1->next);
        L2=((L2==NULL)?headA:L2->next);//若不存在相交结点则返回链表原结构（头结点）
    }
    return L2;//若存在则返回相交位置
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode*p1=headA;
    struct ListNode*p2=headB;
    while(p1!=p2)
    {
        p1=((p1==NULL)?headA:p1->next);
        p2=((p2==NULL)?headB:p2->next);
    }
    return p1;
}