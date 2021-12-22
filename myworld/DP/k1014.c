K.最佳观光组合
/*
https://leetcode-cn.com/problems/best-sightseeing-pair/
*/
/*
给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离。
返回一对观光景点能取得的最高分。
*/
/*也和a题思路一样*/
int maxScoreSightseeingPair(int* values, int valuesSize){
    int max=0;
    int pre=0;
    for(int i=1;i<valuesSize;i++){
        /*保留当前最优解*/
        pre=fmax(pre+values[i]-values[i-1]-1,values[i]+values[i-1]-1);//计算每个点的最大得分
    /*pre+values[i]-values[i-1]-1，pre是前一个结点(i-1)和前面保留下来的得分最大值的结点的的和，
    加上此景点的分数(values[i])，减去前一个结点(i-1)，再减去一的长度（i比i-1多了一长度),
    相当于是用此结点替换前一个结点去和之前的保留最大值计算出得分，并把结果
    和此结点(i)与前一个被替换的结点(i-1)计算（values[i]+values[i+1]-1）出的得分进行比较，保留最大值*/
    
        max=fmax(max,pre);//记录已遍历过的子序列中的最大值
    }
    return max;
}
