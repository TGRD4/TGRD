#include <stdio.h>
#include <curses.h>
#define OK do{\
printf("make the choice:\n");\
printf("1.begin\n");\
printf("0.done\n");\
scanf("%d",&flag);\
}while(0);

struct bigdata
{
    char fuhao;
    char len;
};

int is_number(char* data, struct bigdata* bd);
void cheng01(char* data, struct bigdata bd, char ch, char* result);

int main()
{
    char data[201], result[441];
    char ch;
    int myes,flag;
    struct bigdata bd;
    OK;
    while (flag)
    {
        printf("Input a big data:");
        getchar();
        scanf("%s",data);
        getchar();
        myes = is_number(data, &bd);
        if (!myes)
        {
            printf("%s is not a number.\n", data);
            OK;
            continue;
        }
        else
            printf("%s is a number.\n", data);
        printf("Input a number:");
        ch = getchar();
        cheng01(data, bd, ch, result);
        printf("\n\n%s*%c=%s\n", data, ch, result);
        getchar();
        OK;
    }
}

void cheng01(char* data, struct bigdata bd, char ch, char* result)
{
    int k1, k2, i, j;
    int up;
    int x, y, z;
    if (bd.fuhao == '+' || bd.fuhao == '-') k1 = 1;
    else                                    k1 = 0;
    k2 = bd.len - 1;
    y = ch - 48;
    up = 0;
    for (j = 0, i = k2; i >= k1; i--)
    {
        x = data[i] - 48;
        z = x * y + up;
        result[j++] = z % 10 + 48;
        up = z / 10;
    }
    if (up != 0)
        result[j++] = up + 48;
    if (k1 == 1)
        result[j++] = data[0];
    k1 = 0, k2 = j - 1;
    while (k1 < k2)
    {
        ch = result[k1];
        result[k1] = result[k2];
        result[k2] = ch;
        k1++, k2--;
    }
    result[j] = '\0';
}

int is_number(char* data, struct bigdata* bd)
{
    int len = 0;
    while (data[len] != '\0')
    {
        if (len == 0 && (data[len] == '+' || data[len] == '-'))
            bd->fuhao = data[len++];
        else if (data[len] >= '0' && data[len] <= '9')
            len++;
        else
            return 0;
    }
    if (len == 0) return 0;
    bd->len = len;
    return 1;
}