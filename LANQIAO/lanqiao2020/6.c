#include<stdio.h>
#include<stdbool.h>
int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

/*保证年份合理*/
bool judge(int y,int m,int d) {
	if(y>=10000||m>12||d>days[m]) {			//若是不合理/不存在的日期则返回0
		return false;
	}
	int ok=(y%400==0||(y%4==0&&y%100!=0));	//判断闰年
	if(m==2&&!ok) {
		if(d<=28) {							//非闰年的28号要单独拿出来判断
			return true;
		}
		else {
			return false;
		}
	}
	return true;
}
/*保证年份在给定范围内且在给定年份之后*/
bool smaller(int y1,int m1,int d1,int y2,int m2,int d2) {
	if(y1!=y2) {
		return y2<y1;	//返回的时间必须比给定时间大（向后找回文）
	}
	else {
		if(d1!=d2) {
			return d2<d1;
		}
		else {
			if(m1!=m2) {
				return m2<m1;
			}
			else {		//且不能完全相等！
				return true;
			}
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	/*分别分割出初始年月日*/
	int y1 = n/10000;		// '/'是舍去后面位数
	int m1 = (n/100)%100;	// '%'是保留给定位数（如100就是保留2位）
	int d1 = n%100;			// 保留最后两位作为日期

	/*回文*/
	for(int i=y1;i<10000;i++) {				//不超过给定范围年数
		int y2 = i;							//2020
		int m2 = (i%10)*10+(i/10)%10;		//0+2
		int d2 = ((i/100)%10)*10+i/1000;	//0+2

		if(smaller(y1,m1,d1,y2,m2,d2)) {
			continue;
		}
		if(judge(y2,m2,d2)) {
			printf("%d%02d%02d\n",y2,m2,d2);
			break;	
		}
	}

	/*ABABBABA*/
	int total = y1/100;				//得到前两位，年份日期一定是大于等于total的（ABAB） 
	for(int i=total;i<=99;i++) {	//因为是ABABBABA所以只用考虑前两位（所有位也就被确定了）
		int a = i/10;
		int b = i%10;
		if(a==b) {					//a=b相当于AAAA，不满足
			continue;
		}
		/*凑成ABAB BABA*/
		int y3 = a*1000+b*100+a*10+b;
		int m3 = b*10+a;
		int d3 = b*10+a;
		/*别忘考虑合理性*/
		if(smaller(y1,m1,d1,y3,m3,d3)) {
			continue;
		}
		if(judge(y3,m3,d3)) {
			printf("%d%02d%02d",y3,m3,d3);
			break;	
		}
	}
	return 0;
} 
