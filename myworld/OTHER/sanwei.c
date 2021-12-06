#include <stdio.h>
#include <stdlib.h>
int main() {

    int ***a;
    a = (int ***)malloc(3*sizeof(int**));

    for (int i = 0; i < 3; i++)
    {
        a[i] = (int **)malloc(4 * sizeof(int*));
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = (int *)malloc(5 * sizeof(int));
        }
    }
    for (int t=0; t<3; t++) {
        printf("t = %1d:\n",t+1);
        for (int m = 0; m < 4; m++) {
            for (int n = 0; n < 5; n++) {
                a[t][m][n] = (t+1)*100+(m + 1) * 10 + n + 1;
                printf(" %2d  ", a[t][m][n]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
    return 0;
}
