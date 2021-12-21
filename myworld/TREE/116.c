struct Node* connect(struct Node* root) {
    if (root == NULL) 
        return root;
    // 从根节点开始
    struct Node* leftmost = root;
    while (leftmost->left != NULL) {
        // 遍历这一层结点组织成的链表，为下一层的结点更新 next 指针
        struct Node* head = leftmost;//将树的每一层看作一个链表并引入一个头结点head让其指向表头（这一层的最左结点）
        while (head != NULL) {
            head->left->next = head->right;//改变下一层（让头结点的左结点指向右结点）

            if (head->next != NULL) //因为只有在上一层操作才能改变这一层的左子树的右结点指向右子树的左结点的情况
                head->right->next = head->next->left;//head指向左子树树顶，he ad->next就是右子树树顶
            // 指针向后移动
            head = head->next;//头结点向后移动继续寻找子树
        }
        //这一层找完了就去下一层的最左的结点
        leftmost = leftmost->left;
    }
    return root;
}