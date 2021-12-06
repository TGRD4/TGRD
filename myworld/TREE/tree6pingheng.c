/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode *root)
{
    if(!root)
        return 0;

    int l = height(root -> left);
    if(l == -1)//每个子树都需满足高度平衡,否则就会返回-1
        return -1;
    int r = height(root -> right);
    if(r == -1)
        return -1;

    /*一棵高度平衡二叉树定义为:
    一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1.*/

    if(fabs(l - r) > 1)//差值超过1则不成立
        return -1;
    return fmax(l,r) + 1;//成立则返回最大深度
}

bool isBalanced(struct TreeNode* root)
{
    return height(root) >= 0;//若最大深度是负值则不成立
}
