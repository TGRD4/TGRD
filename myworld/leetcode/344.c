void reverseString(char* s, int sSize)
{
    int left = 0;
    int right = sSize - 1;
    while (left < right) 
    {
        int temp = s[left];//双指针
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void reverseString(char* s, int sSize)
{
    int temp;
    for(int i=0;i<sSize/2;i++)
    {
        temp=s[i];
        s[i]=s[sSize-i-1];
        s[sSize-i-1]=temp;
    }
}

