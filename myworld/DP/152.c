int maxProduct(int* nums, int numsSize){
    long i,realmax = nums[0], max=nums[0], min=nums[0], temp;
    for (i = 1; i < numsSize; i++){
        if(nums[i] < 0) {//遇到负数交换最大值和最小值
            temp = max;
            max = min;
            min = temp;//此时（max为负数/max绝对值较大）在下方与nums[i](负数)可以乘出更大的值
        }
        max = fmax(max*nums[i], nums[i]);
        min = fmin(min*nums[i], nums[i]);//同时保存max和min值（防止出现负负得正的情况）
        realmax = fmax(realmax, max);
    }
    return realmax;
}
/*由于存在负数，那么会导致最大的变最小的，最小的变最大的。
因此还需要维护当前最小值min，当负数出现时则max与min进行交换再进行下一步计算
因为存在负负得正的情况，所以遍历过程同时维护最小负值和最大的正值，最后再取max


举个例子(-2,3,-4)：当nums[2]=-4时若不交换min=-6和max=-2得到的max=8,min=24,
而交换后因为max=-6,min=-2所以得到最终结果为max=24,min=8符合题意。