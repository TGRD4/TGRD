struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL) 
        return t2;
    if (t2 == NULL) 
        return t1;
    struct TreeNode* merged = malloc(sizeof(struct TreeNode));//引入merged指向两数合并后的叶节点
    merged->val = t1->val + t2->val;//若两树相同位置上的叶节点都不为空则将两个叶节点相加
    merged->left = mergeTrees(t1->left, t2->left);//向下依次判断两颗树相同的位置上叶节点的存在情况
    merged->right = mergeTrees(t1->right, t2->right);
    return merged;
}