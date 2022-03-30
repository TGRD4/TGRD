#include<stdio.h>
#include<string.h>
int main()
{
    int sum=0;
    int id=0;
    char now=' ';
    int h=0,m=0;
    int cnt=0;
    int time=0;
    int start[1001]={};//可能从0时开始借阅,并且因为每天借书不是只有一种种类所以要设置为数组而不是整数
    memset(start,-1,sizeof(start));
    scanf("%d",&sum);
    for(int i=0;i<sum;i++) {
        while(1) {
            scanf("%d %c %d:%d",&id,&now,&h,&m);
            if(id!=0) {
                if(now=='S') {
                    start[id]=m+(h*60);//保留某本书的开始借阅时间
                }
                else if(now=='E'&&start[id]!=-1){
                    time+=m+(h*60)-start[id];    //所有书的借阅时长总和
                    cnt++;              //借书次数+1
                    start[id]=-1;   //结束一天的同时重置所有书的借阅记录
                }
            }
            else {      //id=0结束一天的统计
                if(cnt!=0) {
                    printf("%d %0.0f\n",cnt,(float)time/cnt);//注意格式的转换
                }
                else {
                    printf("0 0\n");    //若未出现开始借书记录就出现借书结束记号则记此本书的借录信息为0
                }
                time=0;
                cnt=0;  //别忘了重置
                break;
            }
        }
    }
    return 0;
}