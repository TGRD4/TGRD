#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char g[1010][1010];
bool st[1010][1010];                            //标记此点有没有搜索过
int n;
int total,brink;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};      //标记好四个方向的x,y坐标变化情况
void dfs(int x,int y) {                         //标记此点搜索过
    st[x][y]=true;
    total++;                                    //总路程+1
    for(int i=0;i<4;i++) {                      //向上下左右四个方向进行探索（只要有一个方向是海，那么这个点就是岸边）
        if(g[x+dx[i]][y+dy[i]]=='.') {
            brink++;
            break;
        }
    }
    for(int i=0;i<4;i++) {                      //向四个方向进行探索，记录新点
        int tx=x+dx[i],ty=y+dy[i];                 
        if(tx<0||tx>= n||ty<0||ty>=n) continue; //判断新点的超边情况
        if(g[tx][ty]=='#'&&!st[tx][ty]) {       //和新点是不是陆地和有没有走过的情况（能不能探索）
        /*可以进行dfs的是未走过的陆地，其他情况不考虑*/
            dfs(tx,ty);
        }
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s",&g[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(g[i][j]=='#'&&!st[i][j]) {       //若过此点是陆地且没有被搜索过（路程为0开始搜索）
                total=brink=0;
                dfs(i,j);
                if(total==brink) cnt++;         //如果被淹没的陆地和这一个搜索出的岛屿一样大，那么这个岛就会被完全淹没
                //只要剩下一个都说明不会被淹没
            }
        }
    }
    printf("%d\n",cnt);  
    return 0;
}