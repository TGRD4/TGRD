/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if (p == NULL && q == NULL) //全为空等于相等
        return true;
    else if (p == NULL || q == NULL) //其中一个为空则不相等
        return false;
    else if (p->val != q->val) //根节点不相等则不相等
        return false;
    else//再判断此根节点下的左右结点并且把其作为根节点
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}