#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int Q[18] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char M[12] = { '1','0','X','9','8','7','6','5','4','3','2' };
    char shenfen[101][18]={' '};
    int n=0;
    int sum[101]={0};
    memset(sum,0,sizeof(sum));
    memset(shenfen,0x20,sizeof(shenfen));
    int flag=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s",shenfen[i]);
        int sign=1;
        for(int j=0;j<17;j++) {
            sum[i]+=(shenfen[i][j]-'0')*Q[j];
            /* 查验前17位是否为数字 */
            if(shenfen[i][j]-'0'>9||shenfen[i][j]-'0'<0)
            {
                flag=0;
                sign=0;
                sum[i]=0;
                break;
            }
        }
        /* 查验最后一位的准确性 */
        if(sign) {
            for(int k=0;k<11;k++) {
                if(M[sum[i]%11]==shenfen[i][17]) { //若存在匹配项则直接跳出
                    break;
                }
                else if(k==10&&M[sum[i]%11]!=shenfen[i][17]) { //直到最后一位都不存在匹配项则令sum为0从而最后输出不匹配项
                    sum[i]=0;
                    flag=0;
                }
            }
        }
    }
    if(flag) {
        printf("All passed\n");
        return 0;
    }
    for(int i=0;i<n;i++) {
        if(sum[i]==0) {
            for(int j=0;j<18;j++) {
                printf("%c",shenfen[i][j]);//不能直接输出字符串，注意格式
            }
            printf("\n");
        }
    }
    return 0;
}

/*
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
*/
