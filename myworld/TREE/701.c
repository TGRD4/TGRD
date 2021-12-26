/*
先找出能插入的位置，在位置上根据值建立新的节点
小于根，找左子树
大于根，找右子树
*/
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (root == NULL) {
        //建立链表节点，不要光建val，也要把其他成员也建了
        struct TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (val < root->val) 
        root->left = insertIntoBST(root->left, val);
    else 
        root->right = insertIntoBST(root->right, val);
    return root;
}
