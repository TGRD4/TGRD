/*给定头结点的删除*/
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(!head) return head;
    struct ListNode* p = head;
    while(p->next)
    {
        if(p->val==p->next->val)
            p=p->next;//指针多进行一次移动以删除
        p=p->next;
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head) return head;
    struct ListNode* cur = head;
    while (cur->next)
    {
        if (cur->val == cur->next->val)
            cur->next = cur->next->next;//或者一步到位
        else cur = cur->next;
    }
    return head;
}

/*仅给定需要删除的结点而不使用头指针的结点删除*/
void deleteNode(struct ListNode* node) 
{
 	node->val = node->next->val;//改变此结点指向的数据（保存下一个结点的数据）
  	node->next = node->next->next;//和此结点的指针域使其指向下一个结点的指针域（跳过下一个结点）
}

