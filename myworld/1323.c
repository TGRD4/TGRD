int maximum69Number (int num)
{
    int *s=(int*)malloc(sizeof(int)*5);
    int i=0;
    while(num)
    {
        s[i++]=num%10;
        num/=10;
    }
    for(int j=i-1;j>=0;j--)
    {
        if(s[j]==6) 
        {
            s[j]=9;
            break;
        }
    }
    int sum=0;
    for(int k=0;k<i;k++)
        sum+=(s[k]*pow(10,k));
    return sum;
}