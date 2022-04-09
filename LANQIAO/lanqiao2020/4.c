#include <stdio.h>
#include <math.h>
int main() {
	float k=0;//及格人数 
	float p=0;//优秀人数 
	int n=0;
	int a[101]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++) {
		if(a[i]>=60) {
			k++;
		}
		if(a[i]>=85) {
			p++;
		}
	}
	k=round(k*100/n);//round()可以将参数自动四舍五入
	p=round(p*100/n);
	//printf("%.0lf%%\n%.0lf%%\n",k,p); //%.nlf这个可以自动四舍五入
    //以上两种方法选择一种即可
    printf("%.0f%%\n%.0f%%\n",k,p);
	return 0;
}