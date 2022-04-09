#include <stdio.h>
#include <stdlib.h>
int a[200005], n, m;
int main() {
    scanf("%d %d",&n,&m);
    long long ans = 0;
    int minnum = 0x3f3f3f3f;
    int flagp = 1, flagm = 1;               //全是正数或全是负数
    for(int i = 0; i < n + m + 1; i++) {    //数字数比符号总数多1
        scanf("%d",&a[i]);
        if(!m) {                            // 1.如果没有减号，最大值就是所有数之和
            ans += a[i];
        }

        else {
            if(a[i] < 0) flagp = 0;         // 2.有加和减号并且有正数也有负数
/*此种情况下，只要有负号，就能通过 负负得正把负数转换为正数，
并且通过括号和加号 将所有正数先相加再外套负号转换为正数，从而获得结果就是 所有数的绝对值相加*/
            if(a[i] > 0) flagm = 0;
            if(abs(a[i]) < minnum) {    
                minnum = abs(a[i]);
            }
            ans += abs(a[i]);
        }
    }

    /*当全是负数/全是正数时，不论有多少个负号，都可以通过括号而只剩下一个负号（意思是只用找出绝对值最小的数减去即可）*/
    if(m && (flagp || flagm)) {             // 3.有减号，且全是正数或全是负数
        ans = ans - minnum - minnum;        
        /*减两次的原因是ans之前将它当作正数相加，而它是负数，不仅要恢复到加它之前的原数还要再减去它*/
    }
    printf("%d\n",ans);
    return 0;
}