#include<stdio.h>                  //要求时间复杂度是O(n)
#include<stdlib.h>
int quick_select(int a[], int l, int r, int k) { 
	int p = rand() % (r - l + 1) + l; 
	int x = a[p]; 
    /*利用中括号将交换放在一次防止数据混乱使用，看上去也一目了然*/
    {
		int t = a[p]; 
		a[p] = a[r]; 
		a[r] = t;
	} 
	int i = l, j = r;                //用i替换最左序号，j替换最右序号
	while(i < j) {
		while(i < j && a[i] < x) {   
			i++; 
        }
		if(i < j) {                  
			a[j] = a[i]; 
			j--; 
		} 
		while(i < j && a[j] > x) {   
			j--; 
        }
		if(i < j) {                 
			a[i] = a[j]; 
			i++;
	 	} 
 	}
    a[i] = x; 
    p = i; 
	if(i - l + 1 == k) {
  		return a[i]; 
    }
  	if(i - l + 1 < k) {                             //相当于把i-l+1看作一个下标，将它与5对比
  		return quick_select(a, i+1, r, k-(i-l+1));
        //相当于 当 k<i-l+1 时，找出的就是第 k-(i-l+1) 小元素，在 i+1~r的范围内
    }
    else {
        return quick_select(a, l, i-1, k);        //相当于 当 k>=i-l+1 时，第五小元素在 l~i-1 的范围内
    }
} 
  
int main() {
    int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12}; 
    printf("%d\n", quick_select(a, 0, 14, 5)); 
    //数组，操作数组左序号，操作数组右序号，需找出的第五小元素
    return 0;
}

