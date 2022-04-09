#include<stdio.h>
#include<string.h>
typedef long long ll;
char s[100001];
ll ssum(int x,int y);
int main() {
    ll sum=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++) {
        for(int j=i;j<strlen(s);j++) {
            sum+=ssum(i,j);     //串儿
        }
    }
    printf("%lld\n",sum);
    return 0;
}

ll ssum(int x,int y) {
    ll sum=0;
    int zimu[27]={0};
    for(int i=x;i<=y;i++) {     //标记所有包含的字母
        zimu[s[i]-'a']=1;
    }
    for(int i=0;i<=26;i++) {    //遍历26个字母，若被标记了则不同字母数+1（注意要从0开始）
        if(zimu[i]==1) {
            sum++;
        }
    }
    return sum;
}