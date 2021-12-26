struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (root == NULL) 
            return NULL;
    else{
        if (root->val > val) 
            return searchBST(root->left, val);
        else if (root->val < val) 
            return searchBST(root->right, val);
        else 
            return root;  
    }
}

struct TreeNode* searchBST(struct TreeNode* root, int val){
    while (root) {
        if (root->val > val) return searchBST(root->left, val); //找左边的子树
        if (root->val == val) return root; //找到了，按题目要求返回答案（根）
        if (root->val < val) return searchBST(root->right, val); //找右边的子树
    }
    return NULL; //当root为空，自然返回NULL
}

struct TreeNode* searchBST(struct TreeNode* root, int val){
    while (root) {
        if (root->val == val) return root;//找到，返回答案
        else return searchBST(root->val > val ? root->left : root->right, val); //还没找到，继续找
    }
    return NULL;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    while(root){
        if(root->val==val) return root;
        return searchBST(root->val>val ?root->left:root->right,val);
    }
    return NULL;
}