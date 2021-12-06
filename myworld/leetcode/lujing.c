/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) 
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)//判断到叶子节点的路径之和等不等于target 
        return targetSum == root->val;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);//若未到叶子节点则继续调用自己
}
