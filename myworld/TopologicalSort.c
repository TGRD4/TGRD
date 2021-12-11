#include <stdio.h>
#include <stdlib.h>       //malloc
#include <stdbool.h>      //bool
#define MAXVEX 10         //最大顶点总数
typedef char VerType;     //顶点值类型

/*邻接点域*/
typedef struct EdgeNode   //邻接点域储存当前顶点的编号以及指向下一个结点的指针
{
	int adjvex;           //该顶点对应的编号
	//int weight;（用于存储权值，非网图可以不需要）
	struct EdgeNode* next;//指针域指向下一个结点 
}EdgeNode;


/*当前顶点域*/
typedef struct VertexNode//顶点域存储当前顶点的入度，编号和对应邻接表的头指针
{
	int in;              //入度
	VerType data;        //编号
	EdgeNode* firstedge; //当前顶点的邻接表头指针 
}VertexNode; 


/*总邻接表图*/
typedef struct Graph           //总邻接表中储存所有顶点信息，总顶点数和总边数
{
	VertexNode vers[MAXVEX];   //顶点表
	int numVertexes, numEdges; //顶点数和边数 
}Graph;


/* 拓扑排序，若G没有回路，则输出拓扑排序序列并返回true，若有回路返回false */
bool TopologicalSort(Graph* G)
{
	EdgeNode* e;//邻接点域e
	int i, k, gettop;
	int top = 0;	//栈指针下标
	int cnt = 0;	//统计输出顶点个数
	int* stack;	    //存储入度为0的顶点的栈结构
	stack = (int*)malloc(G->numVertexes * sizeof(int));//为栈分配顶点类型的总顶点大小的内存空间
	
	for(i = 0;i<G->numVertexes;i++) //遍历所有顶点 
		if(G->vers[i].in == 0)
			stack[top++] = i;       //将入度为0的顶点入栈

	while(top)            
    {
		gettop = stack[top--];	    //再依次出栈
		printf("%c ==> ",G->vers[gettop].data);
		cnt++;	                //统计输出顶点数
		for(e=G->vers[gettop].firstedge; e; e = e->next)//对出栈的顶点的邻接表域遍历
		{
			k = e->adjvex;          //邻接顶点编号
			if(!(--G->vers[k].in))	//将k号邻接顶点的入度减1
				stack[++top] = k;	//若入度减为0则入栈，下次循环输出 
		}
	}
	if(cnt < G->numVertexes)	    //如果输出顶点数小于总顶点数，说明存在环，不满足拓扑排序条件
		return false;
	else
    {
        printf("end\n");
		return true; 
    }
}

/* 总图的初始化 */
void CreateGraph(Graph* G)
{
	int i, m, n;
	printf("输入总顶点数和总边数：");
	scanf("%d %d",&G->numVertexes, &G->numEdges);
	printf("输入顶点值：");
    getchar();
	for(i=0;i<G->numVertexes;i++)
    {
		scanf("%c",&G->vers[i].data);
        getchar();
    }

	for(i=0;i<G->numVertexes;i++)
    {
		G->vers[i].firstedge = NULL;     //初始化图的头结点指针指向空
		G->vers[i].in = 0;	             //初始化入度为0 
	}

	printf("输入边的先后关系：\n");
	for(i=0;i<G->numEdges;i++)          //遍历所有边
	{
		scanf("%d %d",&m, &n);          //顶点m指向顶点n，n成为m的邻接顶点
		EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));//为邻接表域分配空间
		newNode->next = (G->vers[m].firstedge == NULL ? NULL : G->vers[m].firstedge);
//若邻接表域的头指针为空（n是第一个邻接顶点），邻接表域的头指针就指向空；若n不是m的第一个邻接点，邻接表域的头指针不变

		newNode->adjvex = n;			//记录新生成的邻接顶点的编号
		G->vers[m].firstedge = newNode; //更新邻接顶点的头指针
		G->vers[n].in++;	            //被指向的邻接顶点的入度+1 
	}
}

int main()
{	
	Graph* G = (Graph*)malloc(sizeof(Graph));//图的内存分配
	CreateGraph(G);//图的创建
	if(TopologicalSort(G))
		printf("拓扑排序完成！\n");
	else
		printf("图存在环！\n");
	return 0;
}
/*
0 1  
0 2
0 4
1 3
3 2
2 4
4 5
3 5
*/
