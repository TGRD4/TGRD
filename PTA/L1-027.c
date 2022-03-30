#include<stdio.h>
#include<string.h>
int main() {
    char number[12]={0};
    char arr[11]={0};
    int index[12]={0};
    int cnt_index=0;
    int cnt_arr=0;
    int cnt_new_arr=0;
    int flag[11]={0};
    scanf("%s",&number);
    for(int i=0;i<strlen(number);i++) {
        if(flag[number[i]-'0']==0) {    //注意字符和数字之间的转换
            arr[cnt_arr++]=number[i];
            flag[number[i]-'0']=1;  //过滤掉统计过的数字
        }
    }

    char new_arr[11]={0};   //对arr数组进行排序形成新arr
    for(int i=9;i>=0;i--) {
        for(int j=0;j<strlen(arr);j++) {
            if(arr[j]-'0'==i) {
                new_arr[cnt_new_arr++]=arr[j];
            }
        }
    }

    for(int i=0;i<strlen(number);i++) {
        for(int j=0;j<cnt_new_arr;j++) {
            if(new_arr[j]==number[i]) {
                index[cnt_index++]=j;
            }
        }
    }
    printf("int[] arr = new int[]{");
    for(int i=0;i<cnt_new_arr;i++) {
        printf("%c",new_arr[i]);
        if(i!=cnt_new_arr-1) 
            putchar(',');
    }
    printf("};\n");
    printf("int[] index = new int[]{");
    for(int i=0;i<cnt_index;i++) {
        printf("%d",index[i]);
        if(i!=cnt_index-1)
        putchar(',');
    }
    printf("};\n");
    return 0;
}