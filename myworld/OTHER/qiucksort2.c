#include<stdio.h>
#include<time.h>
int n, a[1000001], temp;

/*使用二分法当数组很大时得到明显的效率提升*/
void qsort(int l, int r)
{
    if (l >= r) return;
    int mid = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < mid && i <= j) i++;
        while (a[j] > mid && i <= j) j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}


int main()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    clock_t start_time, end_time;
    start_time = clock();   //获取开始执行时间
    qsort(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);


    end_time = clock();     //获取结束时间
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%lf seconds\n", Times);

}




