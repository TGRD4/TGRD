#include<stdio.h>
#include<math.h>
int tree[100001];               //空间过大往外放
int main() {
    int deep=1;                 //初始化deep深度为1
    int sum=0;
    int number=0;
    int max_deep=0;
    int max_sum=-100000000;     //不设置为0的原因是权值不一定都是正数
    scanf("%d",&number);
    for(int i=1;i<=number;i++) {
        scanf("%d",&tree[i]);   //在输入的时候不用刻意去构造一个树，可以通过树的每一行最后一个数的下标来划分数组为树
        sum+=tree[i];
        if(i==pow(2,deep)-1) {  //遇到每行最后一个数 就总结此行总数进行比较和清零
            if(sum>max_sum) {   //记录下最大深度和最大和
                max_deep=deep;
                max_sum=sum;
            }
            sum=0;
            deep++;             //别忘记增加深度
        }
    }
    printf("%d\n",max_deep);
    return 0;
}