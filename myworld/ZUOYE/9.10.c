void to_base_n(unsigned long n,unsigned short t)
{
    if(t>10||t<2) return;
    int r;
    r=n%t;
    if(n>=2) to_base_n(n/t,t);
    printf("%d\n",r);
}