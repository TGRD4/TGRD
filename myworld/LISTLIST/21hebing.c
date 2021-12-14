/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。*/
struct ListNode 
{
    int val;
    struct ListNode *next;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* p3 = (struct ListNode *)malloc(sizeof(struct ListNode));//设置一个新指针指向一个结构体位置
    struct ListNode* p1 = l1, * p2 = l2;//让p1,p2分别指向两个原链表的头结点
    struct ListNode* k = p3;
    while(p1 && p2)//当其中一个链表不为空时一直进行插入操作
    {
        if((p1 -> val) <= ( p2 -> val))//p1->val小则先插入
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
