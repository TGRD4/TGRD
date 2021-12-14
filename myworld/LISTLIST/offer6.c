int* reversePrint(struct ListNode* head, int* returnSize)
{
    *returnSize=0;
    if(head==NULL) return NULL;
    int stack[10001];
    int top=-1;
    while(head)//将链表元素压入栈中
    {
        stack[++top]=head->val;
        head=head->next;
    }
    int* res=(int*)malloc(sizeof(int)*(top+1));
    while(top!=-1)//弹栈
        res[(*returnSize)++]=stack[top--];
    return res;
}

