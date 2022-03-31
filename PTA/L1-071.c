#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
    int sum=0;
    int question=0;
    int number=0;
    int id=1;   //结论编号
    char s[101]={};
    scanf("%d %d",&question,&number);
    for(int i=0;i<number;i++) {
        id=1;
        sum=pow(2,question);//重置编号和全部结果值
        scanf("%s",&s);
        for(int j=0;j<strlen(s);j++) {
            if(s[j]=='n') {//每获得一次否定选项则最后获取id往后移动 当前剩余所有结果数的一半
                id+=sum/2;//列出表格即可找到规律
            }
            sum/=2;//每得到一个确定的结果，结果可能的总数就减少当前剩余结果总数的一半
        }
        printf("%d\n",id);
    }
    return 0;
}