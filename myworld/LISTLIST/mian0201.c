struct ListNode* removeDuplicateNodes(struct ListNode* head) 
{
    if (!head)  return head;
    int* book = (int*)calloc(20001, sizeof(int));//calloc初始化为0
    book[head->val] = 1;
    struct ListNode* pos = head;// 枚举前驱节点
    while (pos->next)           // 当前待删除节点
    {
        struct ListNode* cur = pos->next;
        if (!book[cur->val])//未被标记过的用数组进行标记
        {
            book[cur->val] = 1;
            pos = pos->next;
        } 
        else//标记过的跳过
            pos->next = pos->next->next;
    }
    pos->next = NULL;//严谨
    return head;
}

/*移除链表重复结点*/
struct ListNode* removeDuplicateNodes(struct ListNode* head) 
{
    struct ListNode* p1 = head;
    while (p1) 
    {
        struct ListNode* p2 = p1;
        while (p2->next) 
        {
            if (p2->next->val == p1->val) //若下一个结点与上一个相同，则直接跳过下一个
                p2->next = p2->next->next;
            else 
                p2 = p2->next;
        }
        p1 = p1->next;//遍历整个链表
    }
    return head;//head==NULL直接返回
}

