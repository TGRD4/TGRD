#include<stdio.h>
#include<string.h>
#include<math.h>
int book[8][8];
int bookk[8];
int ans[9999999];   //七位，七个二极管
int sum;
void dfs(int x) {
	int i,k,n,p;
	for(i=1;i<=7;i++) {
		if(bookk[i]==0&&book[x][i]==1) {    //如果当前二极管未被使用过并且有边与它相连则进入图形的组成
			bookk[i]=1;                     //标记当前二极管i被使用过

        /*记录下 连接在一起的二极管
        eg: ans[123]表示二极管1,2,3连接在一起组成了图形*/
			n=0;
			p=0;
			for(k=7;k>=1;k--) {     //倒序的原因是将数字大的二级管放在后面（节省空间）
				if(bookk[k]==1) {   //如果二极管被标记过（bookk[k]==1）则将二极管的序号连接在一起组成序列号p
					p+=k*pow(10,n); //用p记录下所有二极管连接组成的序列号
					n++;            //随着n++，数字越小的组成二极管的位数越靠前
				}
			}
			if(ans[p]==0) {         //若此序列号已经被使用过，说明此图形已经存在，不再记录
				ans[p]=1;
                sum++;              //记录下总图形数
			}
            dfs(i);                 //再从当前图形的另一个相连边开始寻找图形
            bookk[i]=0;             //记录完后记得回复此二极管的使用权
		}
	}
	return ;
}

int main() {
	memset(book,0,sizeof(book));
	memset(bookk,0,sizeof(bookk));
    /*将a~g记为1~7从而标记所有相连的无向边*/
	book[1][2]=book[1][6]=1;		//book[i][j]=1表示i和j边相连
	book[2][1]=book[2][7]=book[2][3]=1;
	book[3][4]=book[3][2]=book[3][7]=1;
	book[4][3]=book[4][5]=1;
	book[5][4]=book[5][6]=book[5][7]=1;
	book[6][1]=book[6][5]=book[6][7]=1;
	book[7][2]=book[7][3]=book[7][5]=book[7][6]=1;
    for (int i=1;i<=7;i++) {	//分别以七个二极管作为源点出发寻找所有图形
        bookk[i]=1; //标记二级管用过
        sum++;      //单个二极管可以组成一个图形
        dfs(i);     //分别以7个二极管作为出发点
        bookk[i]=0; //取消标记从而形成下一种图形
    }
    printf("%d\n",sum);
    return 0;
}

