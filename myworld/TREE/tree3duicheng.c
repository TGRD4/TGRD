/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool judge(struct TreeNode* left,struct TreeNode* right)
{
    if(left == NULL && right == NULL)//左右结点均不存在也对称
        return true;
    if(left == NULL || right == NULL || left -> val != right -> val)//左右结点有一个不存在或者不相等则不对称
        return false;
    return (judge(left -> left,right -> right) && judge(left -> right,right -> left));//判断此结点的左右结点
}
bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)//根节点不存在也是对称
        return true;
    return judge(root -> left,root ->right);
}
