void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int num3[m + n], i = 0, j = 0;
    int cnt = 0;
    while(i < m && j < n)
    {
        if(nums1[i] < nums2[j]) 
            num3[cnt++] = nums1[i++];
        else num3[cnt++] = nums2[j++];
    }
    while(i < m) num3[cnt++] = nums1[i++];//剩下只有相等的情况随便加在后续
    while(j < n) num3[cnt++] = nums2[j++];
    for(i = 0; i < m + n; i++)
        nums1[i] = num3[i];
}
