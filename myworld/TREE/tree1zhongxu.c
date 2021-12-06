/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//中序遍历
void inorder(struct TreeNode* root, int* s, int* sSize) 
{
    if (!root)//若根节点不存在则返回上一次函数调用的地方
        return;
    inorder(root->left, s, sSize);//先遍历左节点
    printf("%d ",root->val);
    inorder(root->right, s, sSize);//最后是右结点
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* s = (int*)malloc(sizeof(int) * 501);//为排序后的新数组分配内存空间
    *returnSize = 0;//数组长度初始化
    inorder(root, s, returnSize);
    return s;
}