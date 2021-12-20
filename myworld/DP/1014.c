int maxScoreSightseeingPair(int* values, int valuesSize){
    int max=0;
    int pre=0;
    for(int i=1;i<valuesSize;i++)
    {
        pre=fmax(pre+values[i]-values[i-1]-1,values[i]+values[i-1]-1);//计算每个点的最大值
    /*pre+values[i]-values[i-1]-1，pre是前一个结点(i-1)和前面保留下来的得分最大值的结点的的和，
    加上此景点的分数(values[i])，减去前一个结点(i-1)，再减去一的长度（i比i-1多了一长度），
    相当于是用此结点替换前一个结点去和之前的保留最大值计算出得分，并把结果
    和此结点(i)与前一个被替换的结点(i-1)计算（values[i]+values[i+1]-1）出的得分进行比较，保留最大值*/
        max=fmax(max,pre);//记录整个数组的最大值
    }
    return max;
}