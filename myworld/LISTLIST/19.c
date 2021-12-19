
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(!head||!(head->next)) return NULL;
    int cnt=0;
    struct ListNode *p1=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
    p1->next=head;//慢指针
    q=p1;
    struct ListNode *p2=head->next;//快指针
    struct ListNode *p=head;
    while(p)
    {
        cnt++;
        p=p->next;
    }
    int dd=cnt-n;
    while(dd--)
    {
        p1=p1->next;
        p2=p2->next;
    }//找到要删除的结点并且把它放在快慢指针中间，直接用慢指针指向快指针以删除目标结点
    p1->next=p2;
    return q->next;
}

