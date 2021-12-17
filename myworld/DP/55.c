bool canJump(int* nums, int numsSize){
    int x = 0;
    for (int r = 0; x < numsSize && x <= r; x++) 
        r = fmax(r, x + nums[x]);
    /*将这一点的位置（下标x）与从这一点能跳出的最大长度（距离nums[x]）相加，
    得到从这一点跳到下一点的最大位置，与从前一点能跳到的最大位置相比，保留最大值，
    如果能达到的最大位置（r）小于这一点的位置，说明无论如何前面的点都跳不到当前这一点，那么后面的位置也更到不了，返回false
    如果循环结束了，也没有找到到不了的点，那就返回true*/
    return x >= numsSize;
}
