struct ListNode* removeElements(struct ListNode* head, int val)
{
    while (head != NULL && head->val == val)//因为需要返回头结点所以要先找到返回的头结点
        head = head->next;//若前几个结点都是需要删除的结点则头结点一直后移（顺便删除前几个结点）
    if (head == NULL)  return NULL;//此处还需要再判断一次当前是不是空链表
    struct ListNode* p = head;
    while(p->next) 
    {
        if (p->next->val==val)//若当前结点的下一结点是要删除的结点
            p->next=p->next->next;//则让p->next直接移到下下个结点
        else p=p->next;
    }
    return head;
}
