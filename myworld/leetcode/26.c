int removeDuplicates(int* nums, int numsSize)
{
    int *p = nums;
    int count=0;
    if(numsSize==0)
        return 0;
    for(int i=0;i<numsSize-1;i++)//不减1下方判断会溢出
    {
        if(*p == *(p+1))
        {
            p++;
            count++;//重复数字计数
        }
        else
        {
            nums[i-count+1]=nums[i+1];//第一次出现的数代替重复的数
            p++;
        }
    }
    return (numsSize-count);//未重复数字(总长)
}
