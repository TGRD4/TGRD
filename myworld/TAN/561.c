int cmp(const void*x,const void*y)
{
    return *(const int*)y-*(const int*)x;
}
int arrayPairSum(int* nums, int numsSize)
{
    int max=0;
    qsort((void*)nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize;i+=2)
        max+=fmin(nums[i],nums[i+1]);
    return max;
}