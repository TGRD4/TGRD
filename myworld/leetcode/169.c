int majorityElement(int* nums, int numsSize)
{
     int *stack=malloc(sizeof(int)*numsSize);
     int top=-1;
     for(int i=0;i<numsSize;i++)
     {
         if(top==-1)
             stack[++top]=nums[i];
         else if(stack[top]==nums[i])
             stack[++top]=nums[i];
         else top--;
     }
     return stack[0];
}
/*
int majorityElement(int* nums, int numsSize)
{
    int key = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i] == key)
            count++;
        else
            count--;
        if(count <= 0)
            key = nums[i+1];
    }
    return key;
}
//第二种方法
/*int partition(int *a,int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot)high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quickSort(int *a,int low,int high){
    if(low<high){
        int pivotpos=partition(a,low,high);
        quickSort(a,low,pivotpos-1);
        quickSort(a,pivotpos+1,high);
    }
}
int majorityElement(int* nums, int numsSize){
    quickSort(nums,0,numsSize-1);
    return nums[numsSize/2];
}
*/