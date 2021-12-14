bool isPalindrome(struct ListNode* head) 
{
    int vals[100001], k = 0;
    while (head) 
    {
        vals[k++] = head->val;//将链表所有值储存在一个数组里
        head = head->next;
    }
    for (int i = 0, j = k- 1; i < j; i++, j--) 
    {
        if (vals[i] != vals[j])//从最前和最后开始逐一比较数组中的每个值
            return false;
    }
    return true;
}
/*-----------------------------------------------------------------*/

/*递归*/
struct ListNode* frontPointer;//定义前指针

bool recursivelyCheck(struct ListNode* currentNode) 
{
    /*递归到尾结点的下一结点后返回ture，进入第三个if判断，若一直相等则前指针向后移动并且返回true，
    返回递归上一级，因为是true（不满足第二个if条件）所以再进入第三个if判断，一直重复上述步骤*/
    if (currentNode)
    {
        if (!recursivelyCheck(currentNode->next))//递归返回时后指针逐渐向前移动
            return false;
        if (currentNode->val != frontPointer->val)//一旦不相等false后会一直递归返回false
            return false;
        frontPointer = frontPointer->next;//前指针向后移动
    }

    return true;/*两种情况：1.递归结束(currentNode为空)并开始返回的条件(找到尾结点) ；
    2.如果当前结点为空（比较完了并且全部相等），是回文链表*/
}

bool isPalindrome(struct ListNode* head) 
{
    frontPointer = head;
    return recursivelyCheck(head);
}