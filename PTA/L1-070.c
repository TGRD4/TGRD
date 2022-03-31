#include<stdio.h>
#include<string.h>
int main() {
    char hotpot[15]={"chi1 huo3 guo1"};
    char input[81]={};
    int sum=0;
    int keep=0;
    int cnt=0;
    int flag=0;
    while(1) {
        //memset(input,' ',sizeof(input));
        //fgets(input,sizeof(input),stdin); 
        gets(input);
        if(strcmp(input,".")==0) {
            break;
        }
        sum++;
        /* C 库函数 char *strstr(const char *haystack, const char *needle)
        在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。*/
        /*
        该函数返回在 haystack 中第一次出现 needle 字符串的位置，如果未找到则返回 null。
        */
        char *p=strstr(input,hotpot);
        if(p) {
            if(flag==0) {
                keep=sum;
                flag=1;
            }
            cnt++;
        } 
    }
    printf("%d\n",sum);
    if(cnt!=0) {
        printf("%d %d\n",keep,cnt);
    }
    else {
        printf("-_-#\n");
    }
    return 0;
}