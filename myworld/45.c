int jump(int* nums, int numsSize){
    int n = 0;
    for(int x = 0,r = 1;r < numsSize;++n){
        int right = r;
        for(;x < r;++x)
            right = fmax(right,x + nums[x] + 1);
        r = right;
    }
    return n;
}
int jump(int* nums, int numsSize){
    int steps = 0, end = 0, maxPos = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        maxPos = nums[i] + i < maxPos ? maxPos : nums[i] + i;
        if (i == end) {
            end = maxPos;
            ++steps;
        }
    }
    return steps;
}
