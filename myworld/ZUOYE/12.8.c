int *make_array(int elem,int val)
{
    int*p=(int*)malloc(elem*(sizeof(int));
    if(p==NULL) return NULL;
    for(int i=0;i<elem;i++)
        p[i]=val;
    return p;
}

void show_array(const int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
        if((i+1)%8==0)
            printf("\n");
    }
    putchar('\n');
}