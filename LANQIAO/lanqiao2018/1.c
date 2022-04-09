#include<stdio.h>
void zheng(int n);
void fu(int n);
int main() {
    freopen("in.txt","r",stdin);
    int n;
    for(int i=0;i<10;i++) {
        for(int j=0;j<32;j++) {
            scanf("%d",&n);     //n充当进入输入流的字符（n从"in.txt"中获取）
            if(n>=0) {
                zheng(n);
            }
            else if(n<0) {      //负数的二进制是补码
                fu(n);
            }
            if((j+1)%2==0) {    //两个字节一行（记得加1(因为下标从0开始)要不出不来结果）
                putchar('\n');
            }
        }
        printf("11111111111111111111111111\n");
    }
    return 0;
}

void zheng(int n) {
    int s[9]={0};               //s数组存储转换的二进制数
    for(int i=0;i<8;i++) {
        s[i]=n%2;
        n/=2;
    }
    for(int i=7;i>=0;i--) {     //因为存的时候是反着存的，输出记得一定要反着来
        if(s[i]==0) {           //0是底色（不输出）
            printf(" ");
        }
        else if(s[i]==1) {      //1是墨迹
            printf("*");
        }
    }
    return ;
}

void fu(int n) {
    int s[9]={0};
    n=-n;
    int k;
    for(k=0;k<8;k++) {
        /*因为负数是取反码+1，所以与正数相反，0位变1，1位变0*/
        s[k]=(n%2?0:1);
        n/=2;
    }
    
//第一位是0直接转为补码（相当与二进制码的最后一位），补码就是反码直接+1，若最后一位是0就可以直接+1而不影响其它位
    if(s[0]==0) {   
        s[0]=1;

        /*输出*/
        for(k=7;k>=0;k--) {
            if(s[k]==0) {
                printf(" ");
            }
            else {
                printf("*");
            }	
        }
    }

//最后一位是1则需要进位，判断最后一位之前的所有位的进位情况
    else {          
        s[0]+=1;                //标记需要进位的位数上的数为2
        for(k=0;k<8;k++) {
            if(s[k]==1) {       //如果1表示无需进位
                break;
            }
            else if(s[k]==2) {  //2表示进位，令前一位+1并且令此位为0
                s[k]=0;
                s[k+1]+=1;
            }
        }

        /*输出*/
        for(k=7;k>=0;k--) {
            if(s[k]==0) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }	
    }
    return;
}
