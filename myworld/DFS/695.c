int dfs(int** grid, int i, int j, int gridSize, int* gridColSize)
{
	int cnt = 1;
	grid[i][j] = 0;//删除已统计过的岛屿 
	if (i + 1 < gridSize && grid[i+1][j])//分别统计向四个方向走的情况
		cnt += dfs(grid, i + 1, j,gridSize, gridColSize);
	if (i - 1 >= 0  && grid[i-1][j])
		cnt += dfs(grid, i - 1, j,gridSize, gridColSize);
	if (j + 1 < gridColSize[i] && grid[i][j+1])
		cnt += dfs(grid, i, j + 1,gridSize, gridColSize);
	if (j - 1 >= 0 && grid[i][j-1])
		cnt += dfs(grid, i, j - 1, gridSize, gridColSize);
	return cnt;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
	int max= 0;
	int cnt = 0;
	for (int i = 0; i <gridSize; i++){
		for (int j = 0; j< gridColSize[i]; j++){
			if (grid[i][j]){
				cnt= dfs(grid, i, j, gridSize, gridColSize);
				max = fmax( max , cnt);
			}
		}
	}
	return max;
}