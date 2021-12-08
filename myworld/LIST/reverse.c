/*迭代法反转链表*/

/*核心思想是设置三个指针分别指向（待被反转后指针指向的结点front  指针域指向要反转的结点mid  待被反转的结点last），
从头结点开始通过三个指针的移动逐渐完成链表的反转*/

struct Link* Iteration(struct Link* head)//也可以从头结点开始
{
    struct Link*front=NULL;//使front指向首元结点前的位置
    struct Link*mid=head;//mid指向首元结点
    struct Link*last=head->next;//last指向第二个结点

    if(head==NULL||head->next==NULL)//若链表中只有一个结点则它反转后就是本身
    {
        return head;//返回它本身
    }
    else//若链表中不止一个结点
    {
        while(1)//一直反转直到所有结点的指针域都指向前一个结点
        {
            mid->next=front;//使当前正在反转的结点的指针域指向前一个结点
            if(last==NULL)/*此时需要判断待反转的结点是不是为空，
                            若为空说明此时mid已经是最后一个结点，不用再继续反转*/
            {
                break;
            }
            front=mid;//若反转的不是最后一个结点则把三个指针都向后移一位以进行下一次反转
            mid=last;
            last=last->next;
        }
    }
    head = mid;//使最后一个被反转的结点成为新的首元结点，完成反转
    return head;//返回指向首元结点的指针
}




/*递归法反转链表*/

/*算法思想和迭代相似但是操作相反（从尾结点开始反转），首先利用递归找到尾结点，
再利用递归的逐级返回性质设置一个指针head，让其新指向前一个待反转的从结点直到遇到原头结点，从而逐渐反转链表*/

/*此处设置两个结点：前结点和后结点：
后结点一开始是尾结点，前结点一开始是尾结点的前一个结点，在递归过程中这两个结点一直在一起向前移动（通过递归的逐级返回而移动），
此时设置一个head指针让其指向前结点，反转就是让后结点的指针域指向前结点，
相当于前结点是待反转的结点，而后结点是正在反转的结点*/

struct Link* Recursive(struct Link* head)
{
    if (head == NULL || head->next == NULL)//递归出口（并且判断链表是否只存在一个结点）
    {
        return head;/*在链表不只有一个结点的情况下，若找到了尾结点，
        说明此时head->next==NULL，递归返回一层，head作为返回值赋给newhead，
        newhead成为尾结点，而返回后的head是head->next，所以head是倒数第二个结点*/
    }
    else
    {
        //一直递归，直到找到链表中最后一个结点
        struct Link *newhead = Recursive(head->next);//与迭代不同，一开始就找到了新头结点
        /*当逐层退出时，newhead的指向一直不变，一直指向原链表中尾结点（新的头结点），
        而head的指向一直在改变（指向待被反转的结点）*/

        head->next->next = head;/*使head所指结点（前结点）的指针域指向的结点（就是后结点）
        的指针域指向前结点，以确定下一个要反转的结点（就是前结点）*/
        head->next = NULL;//head所指结点的指针域为NULL（若不置为NULL，会使两个结点的指针域互指）

        return newhead;/*每一层递归结束，都要将指向新头结点（尾结点）的指针返回给上一层，
                        保证整个递归过程中，一直找得到新表头（因为最后函数的返回值是反转后的链表头指针，
                        而我们并不知道什么时候递归结束，所以要在每层递归结束后都返回新头指针）*/
    }
}




/*头插法反转链表*/

/*核心思想是从头结点开始顺序取出原链表中的所有结点并把这些结点逐个通过头插法插入到一个空链表中*/

struct Link *Headinsert(struct Link *head)
{
    struct Link * new_head = NULL;//新创建的链表的头结点为空
    struct Link * temp = NULL;//待插入的结点为空
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    while (head != NULL)//当原链表的头结点不为空时
    {
        temp = head;//头结点成为了待插入的结点
        head = head->next;//下一个待插入的结点作为新的头结点

        temp->next = new_head;/*将原链表头结点头插入新链表的头部
        （头插法就是让新插入结点的指针域指向链表的头结点）*/
        new_head = temp;//新的头结点就是新插入的结点
    }
    return new_head;//返回新的头结点，此时原链表的尾结点成为了新链表的头结点，完成反转
}




/*就地逆置法反转链表*/

/*与头插法思想相同，不同在于不用创建新的链表而是直接在原链表上做修改，只不过这样就需要借助两个指针front和last来帮助记录位置*/

struct Link *Local(struct Link* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Link * front = head;//创建front指针指向首元结点
    struct Link * last = head->next;//last指向首元结点的下一个结点
    while (last != NULL) //当存在下一个结点的时候
    {
        front->next = last->next;//将last从链表中摘除
        last->next = head;//将last移动至表头
        head = last;//last成为新表头（为反转下一个结点做准备）
        last = front->next;//重置last为需要摘除的下一个结点（原last的下一个结点）
    }
    return head;
}
