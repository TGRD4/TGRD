 void dfs(int **image,int x,int y,int color,int newColor,int imageSize, int* imageColSize){
        //  如果坐标越界就不用涂色
    if (x<0||x>=imageSize||y<0||y>=imageColSize[0]) 
        return;
            // 如果周围颜色与初始的颜色一致，则将他涂成新的颜色，并向上下左右dfs
    if (image[x][y] == color) {
        // 将颜色替换
        image[x][y] = newColor;
        // 深度优先搜索四周的像素点
        dfs(image, x-1, y, color, newColor,imageSize, imageColSize);
        dfs(image, x+1, y, color, newColor,imageSize, imageColSize);
        dfs(image, x, y-1, color, newColor,imageSize, imageColSize);
        dfs(image, x, y+1, color, newColor,imageSize, imageColSize);
    }
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    // 这里要判断一下初始颜色和新的颜色是否一样，不然会造成无限递归
    if (image[sr][sc]!= newColor) 
        dfs(image, sr, sc, image[sr][sc], newColor,imageSize,imageColSize);
	*returnSize = imageSize;
	*returnColumnSizes = imageColSize;
    return image;
}
