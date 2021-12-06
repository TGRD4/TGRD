/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*将数组转换为树*/


struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if(numsSize)
    {
        int mediaNum = numsSize/2;//定位新结点
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));//为新树分配空间
        
        /*处理新树*/
        root->val = nums[mediaNum];//新树根结点
        root->left = sortedArrayToBST(nums,mediaNum);//新树左节点
        root->right = sortedArrayToBST(nums + mediaNum + 1, numsSize - mediaNum -1);//新树右结点
        
        return root;
    }
    return NULL;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if((nums==NULL) || (numsSize==0)) return NULL;
    int Root = 0;
    struct TreeNode* p = NULL;
    p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    Root = numsSize / 2;//定位根节点
    p->val = nums[Root];
    p->left = sortedArrayToBST(&nums[0], Root);//递归处理左右分支
    p->right = sortedArrayToBST(&nums[Root + 1], numsSize - Root - 1);
    return p;
}


struct TreeNode *BuildBST(int *nums, int left, int right)
{
    if (left > right) 
        return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int mid = (left + right) / 2;
    root->val = nums[mid];
    root->left = BuildBST(nums, left, mid - 1);
    root->right = BuildBST(nums, mid + 1, right);
    return root;
}
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    return BuildBST(nums, 0, numsSize-1);
}

