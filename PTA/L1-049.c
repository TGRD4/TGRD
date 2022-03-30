#include<stdio.h>
/*为了防止漏数字设置num++让其逐个输出*/
/*主：map图*/
int main() {
    int map[101][101]={0};  //初始化0
    int sum=0;
    int max=0;
    int team[101]={0};
    scanf("%d",&sum);

    for(int i=0;i<sum;i++) {
        scanf("%d",&team[i]);
        if(max<team[i]) {
            max=team[i];//保留最多学生的队伍数
        }
        for(int j=0;j<team[i]*10;j++) {
            map[i][j]=1;    //将每个学校的学生作为一个矩阵，并将其对应大小的值都设为1，方便后续判断每个学校排座位的完成情况
        }
    }

    int flag=-1;//用 flag 记录上一个人的学校，初始化为-1,因为 j 初始值是 0
    /*将 sum 个矩阵逐个赋值(num++，不会漏掉数字)，但是只给每个矩阵对应大小的范围设正值方便最后输出*/

    int num=1;
    for(int i=0;i<max*10;i++) {
        for(int j=0;j<sum;j++) {

            /*只处理存在学生的位置*/
            if(map[j][i]) {     //j就是此人所处学校
                if(flag!=j){    //若和上一个人处于不同的学校
                    map[j][i]=num++;    //紧跟着排座位
                    flag=j;     //记录此人的学校，此人成为上一个人
                }
                else {      //若上一个人和这一个人的学校一样（已排除 map=0 的情况，就是这个学校不存在这么多参赛学生)
                    num++;
                    map[j][i]=num++;//隔一个座位排座
                    flag=j;//再次记录下学校
                }
            }

        }
    }

    for(int i=0;i<sum;i++) {
        printf("#%d\n",i+1);
        for(int j=0;j<max*10;j++) {
            if(map[i][j]) {     //别忘了舍去每个矩阵后面的0（不存在的学生）
                printf("%d%c",map[i][j],(j+1)%10==0?'\n':' ');//要么后跟' '要么'\n'，仅两种情况
            }
        }
    }
}