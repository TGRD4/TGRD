/*二叉搜索树的特点：左子叶小于父叶，右子叶大于父叶*/
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    struct TreeNode* ancestor = root;
    while(1) 
    {
        if (p->val < ancestor->val && q->val < ancestor->val)//目标结点都比当前结点小则在左子树上
            ancestor = ancestor->left;
        else if (p->val > ancestor->val && q->val > ancestor->val)//反之在右子树上
            ancestor = ancestor->right;
        else break;
    /*若其中不同时满足>/<则直接返回当前结点，因为根据二叉搜索树的性质，要出现当前结点的一个子结点而大一个子结点小的情况，
    就说明这三个结点一定在一个子树上，则两个目标结点的公用结点一定就是当前结点*/
    }
    return ancestor;
}
