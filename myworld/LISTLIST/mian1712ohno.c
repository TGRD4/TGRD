/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, struct TreeNode** head, struct TreeNode** pre)
{
    if(root == NULL)  return;
//递归左子树
    inorder(root->left, head, pre);        
//访问根节点
    if(*pre == NULL)
    {
        *head = root;
        *pre = root;
    }
    else
    {
        (*pre) -> right = root;    //前驱节点的右孩子是当前节点
        (*pre) = root;             //更新前驱节点为当前节点
        root->left = NULL;         //当前节点的左孩子置空
    }
//递归右子树
    inorder(root->right, head, pre);       
}
struct TreeNode* convertBiNode(struct TreeNode* root)
{
    struct TreeNode* head=NULL;    //head记录第一个节点
    struct TreeNode* pre =NULL;    //pre记录当前节点的前一个结点
    inorder(root, &head, &pre);
    return head;
}
