#include <stdio.h>
#include <string.h>
#include <ctype.h>
char talk[21][2021];
char new_talk[21][2021];
int i;
int cnt;

int the_type(char ch);
int solo_str(int x,int y);

int main() {
    int sum=0;
    scanf("%d",&sum);
    getchar();
    for(;i<sum;i++) {
        cnt=0;
        memset(new_talk,' ',sizeof(new_talk));
        fgets(talk[i],sizeof(talk[i]),stdin);
        printf("%s",talk[i]);
        int len=strlen(talk[i]);

        /* 去除前后空格 */
        int start=0;
        int end=len-1;
        while(talk[i][start]==' ') start++;
        while(talk[i][end]==' ') end--;


        /* 格式转换 */
        for(int j=start;j<=end;j++) {
            if(talk[i][j]!='I'&&the_type(talk[i][j])==2) {
                new_talk[i][cnt++]=talk[i][j]+32;
            }
            else if(talk[i][j]=='?') {
                new_talk[i][cnt++]='!';
            }
            else if(talk[i][j]==' '&&(talk[i][j+1]==' '||the_type(talk[i][j+1])==5)) {
                continue;
            }
            else {
                new_talk[i][cnt++]=talk[i][j];
            }
        }

        int flag1=1,flag2=1;
        printf("AI: ");
        /* 对新字符串进行操作 */
        for(int j=0;j<cnt;j++) {
            if(new_talk[i][j]=='I'&&solo_str(j-1,j+1)) {
                printf("you");
            }
            else if(new_talk[i][j]=='m'&&new_talk[i][j+1]=='e'&&solo_str(j-1,j+2)) {
                printf("you");
                j++;
            }
            else if(flag1&&strstr(new_talk[i],"can you")&&solo_str(j-1,j+7)) {
                flag1=0;
                printf("I can");
                j+=6;
            }
            else if(flag2&&strstr(new_talk[i],"could you")&&solo_str(j-1,j+9)) {
                flag2=0;
                printf("I could");
                j+=8;
            }
            else {
                printf("%c",new_talk[i][j]);
            }
        }
    }
    return 0;
}

int the_type(char ch) {
    if(ch<='z'&&ch>='a') return 1;
    else if(ch<='Z'&&ch>='A') return 2;
    else if(ch>='0'&&ch<='9') return 3;
    else if(ch==' ') return 4;
    else return 5;
}

int solo_str(int x,int y) {
    if((the_type(new_talk[i][x])==4||the_type(new_talk[i][x])==5||x<0)&&
    (the_type(new_talk[i][y])==4||the_type(new_talk[i][y])==5||y>cnt))
        return 1;
    return 0;
}
