struct ListNode 
{
     int val;
     struct ListNode *next;
};
bool hasCycle(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)   //空链表和只有一个结点的链表没有环
        return false;
    struct ListNode* p, * q;                  //p为慢指针，q为快指针
    p = head;                                 //初始化快慢指针
    q = head->next;
    while (q != NULL && q->next != NULL)      //两个指针遍历链表（快指针到尾结点之前退出）
    {    
        if (q == p)                           //快慢指针访问同一个结点，则该链表有环
            return true;
        p = p->next;                          //慢指针一次移动一步
        q = q->next->next;                    //快指针一次移动两步
    }
    return false;                             //两个指针没有相遇，无环
}
