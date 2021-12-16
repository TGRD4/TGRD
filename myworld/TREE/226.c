struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL) return NULL;
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);//从底往上交换每一个子树的左右子结点，越靠近根节点交换一次的结点就越多
    root->left = right;
    root->right = left;//交换左右结点
    return root;
}
