void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {//column列
    int m = matrixSize;
    int n = matrixColSize[0];
    int row[m], col[n];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));//先将行列都置为0表示没有行列存在0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) //标记存在0的行列为1
                row[i] = col[j] = true;//#include <stdbool.h>(true=1,false=0)
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) //将被标记的行列都置为0
                matrix[i][j] = 0;
        }
    }
}
