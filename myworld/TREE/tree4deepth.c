/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//max
int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return fmax(maxDepth(root -> left),maxDepth(root -> right)) + 1;//fmax包含于<math.h>函数中,返回两数中最大值(double float long int)
}
//min
int minDepth(struct TreeNode* root)
{
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL) return 1;//若都只有一个根节点则返回深度为1
    int min = INT_MAX;//表示无限大
    if(root -> left != NULL)//哪个节点不为空则遍历哪个节点
        min = fmin(minDepth(root -> left),min);
    if(root -> right != NULL)
        min = fmin(minDepth(root -> right),min);
    return min + 1;//每调用一次自身加一次深度(说明有一个父节点存在子结点)
}