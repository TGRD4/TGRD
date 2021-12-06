#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>
int main(int argc)
{
    char str1[100];
    char str2[100];
    int i = 0;
    int j = 0;
    int num1 = 0;
    int num2 = 0;
    printf("�����һ�����֣�");
    scanf("%s", &str1);
    while (str1[i] != '\0')
    {
        if (!(47 < str1[i] && str1[i] < 58))
        {
            printf("ֻ���������֣��������룺");
            scanf("%100s", &str1);//%100s���������ַ���100�����ڣ�ȱ�ݣ��������������뵽�¸��ַ��У�����str2���ַ���
            i = 0;
        }
        i++;
    }
    num1 = i;
    printf("����ڶ������֣�");
    scanf("%s", &str2);
    i = 0;
    while (str2[i] != '\0')
    {
        if (!(47 < str2[i] && str2[i] < 58))
        {
            printf("ֻ���������֣��������룺");
            scanf("%100s", &str2);
            i = 0;
        }
        i++;
    }
    num2 = i;
    char* result;
    int* s = (int*)malloc(sizeof(int) * (num1 + num2));
    for (i = 0; i < num2 + num1; i++)
        s[i] = 0;
    printf("The s is :%d and %d\n", num1, num2);
    for (i = 0; i < num1; i++)
        for (j = 0; j < num2; j++)
            s[i + j + 1] += (str1[i] - '0') * (str2[j] - '0');//��λ���ϸ���˻������������ڳ˷�����ʽ����
    for (i = num1 + num2 - 1; i >= 0; i--) {
        if (s[i] >= 10) {
            s[i - 1] += s[i] / 10;//�����һλ��ʼ���������Ԫ��ֵ>10��������һλ��ֵ+1��
            s[i] %= 10;         //������ֵΪ����10������������÷��Ͻ�һλ
        }
    }
    i = 0;
    while (s[i] == 0)//�ӵ�һλ��ʼ���ҵ���Ϊ0���ǵڼ�λ��Ϊ��ɾ��ǰ������0��s[0]һ��ʼ�ͱ���ֵΪ0��
        i++;
    result = (char*)malloc(num1 + num2 + 1 - i);//��ȥ�����λ��i������׼ȷ�Ŀռ��result
    for (j = 0; i < num1 + num2; i++, j++) {
        result[j] = s[i] + '0'; //��s��ֵ����result��result�ӵ�0λ��ʼ����ֵ
    }
    result[j] = '\0';  //result�����Ͻ�β
    free(s); //�ͷ�s�ռ�
    printf("The number %s multiply %s\nresult in %s.\n", str1, str2, result);
    getchar();
    getchar();
    return 0;
}