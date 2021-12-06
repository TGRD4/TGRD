#include<stdio.h>
#include<time.h>
void quicksort(int left, int right,int s[]);
int main()
{
	int s[1001];//也可以把数组和个数作为全局变量而不用每次都调用数组入函数
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

    clock_t start_time, end_time;
    start_time = clock();   //获取开始执行时间
	quicksort(0, n-1,s);
	for (i = 0; i < n; i++)
		printf("%d ", s[i]);
    end_time = clock();     //获取结束时间
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%lf seconds\n", Times);
}

void quicksort(int left, int right, int s[])
{
	int i, j, t, temp;
	if (left > right)
		return;
	temp = s[left]; //temp中存的就是基准数 
	i = left;
	j = right;//位置

	while (i != j)
	{
		//顺序很重要，要先从右往左找 
		while (s[j] >= temp && i < j)
			j--;
		//再从左往右找 
		while (s[i] <= temp && i < j)
			i++;
		//交换两个数在数组中的位置 
		if (i < j)//当哨兵i和哨兵j没有相遇时
		{
			t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	//最终将基准数归位 
	s[left] = s[i];
	s[i] = temp;
	quicksort(left, i - 1,s);//继续处理左边的，这里是一个递归的过程 
	quicksort(i + 1, right,s);//继续处理右边的，这里是一个递归的过程 
}