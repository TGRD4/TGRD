int firstBadVersion(int n) 
{
    int left = 1, right = n;
    while (left < right) 
    {  
        int mid = (right - left) / 2 + left ; 
        if (isBadVersion(mid)) //mid出错，之后版本都错
            right = mid;//在前面找
        else 
            left = mid + 1;//mid没错，出错版本在后面
    }
    return left;//返回最开始出错的版本
}