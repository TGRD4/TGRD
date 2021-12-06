#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>

char e;
/*提醒用户是否确认自己的操作*/
#define OK do{\
printf("continue or quit?(c/q):");\
getchar();\
scanf("%c",&e);\
}while(0);

/*学生信息结构*/
typedef struct node
{
	char name[20];//姓名
	int number;//学号
	struct node* next;
}Node, * LinkList;

/*初始化链表*/
LinkList InitList()
{
1 2 3 4 5 6 7 -1
	return head;
}

/*判断重复信息*/
int judge(LinkList head,int number1,char name1[])
{
    Node*p=head;
    while(p)
    {
        if(strcmp(p->name,name1)==0&&p->number==number1)
        {
            printf("all");
            return 0;
        }
        else if(p->number==number1)
        {
            printf("id");
            return 0;
        }
        else if(strcmp(p->name,name1)==0)
        {
            printf("name");
            return 0;
        }
        p=p->next;
    }
    return 1;
}

/*判断重复id*/
int judge_id(LinkList head,int number1)
{
    Node*p=head;
    while(p)
    {
        if(p->number==number1)
        {
            printf("id repeated!\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}

/*判断重名*/
int judge_name(LinkList head,char name1[])
{
    Node*p=head;
    while(p)
    {
        if(strcmp(p->name,name1)==0)
        {
            printf("name repeated!\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}

/*/尾创链表*/
void CreatByRear(LinkList head)
{
	Node*r, *s;
	char name[20];
	int number;
	r = head;
    OK;
    if(e=='c'||e=='C')
    {
        printf("please input the information:\n");
        scanf("%s", name);
	    scanf("%d", &number);
        if (number == 0)//当输入学号为0时退出输入
		    return;
		s = (Node*)malloc(sizeof(Node));
		strcpy(s->name, name);
		s->number = number;
		r->next = s;
		r = s;
        while (1)
	    {
            scanf("%s", name);
		    scanf("%d", &number);
            if (number == 0)
			    return;
            if(judge(head,number,name))
            {
                s = (Node*)malloc(sizeof(Node));
	            strcpy(s->name, name);
	            s->number = number;
	            r->next = s;
	            r = s;
            }
            else printf(" repeated! please input again!\n");//学号和姓名均不可重复
        }
	    r->next = NULL;
    }
	getchar();
}

/*头创链表*/
void CreatByHead(LinkList head)
{
	Node* s;
	char name[20];
	int number;
    OK;
    if(e=='c'||e=='C')
    {
		printf("please input the information:\n");
		scanf("%s", name);
		scanf("%d", &number);
		if (number == 0)
			return;
		s = (Node*)malloc(sizeof(Node));
		strcpy(s->name, name);
		s->number = number;
		s->next = head->next;
		head->next = s;
		while (1)
		{
			scanf("%s", name);
			scanf("%d", &number);
			if (number == 0)
				return;
			if(judge(head,number,name))
			{
				s = (Node*)malloc(sizeof(Node));
				strcpy(s->name, name);
				s->number = number;
				s->next = head->next;
				head->next = s;
			}
			else printf(" repeated! please input again!\n");
		}
    }
	getchar();
}

/*插入学生信息*/
void Insert(LinkList head)
{
	char ok;
	int i,j,number;
    char name[20];
	Node* p=head, * s;
    OK;
    if(e=='c'||e=='C')
    {
	    do
		{
			p=head;
			j=0;
			printf("please input the position:");//输入插入位置
			scanf("%d", &i);
			while (j < i - 1 && p)
			{
				p = p->next;
				j++;
			}
			if (p)
			{
				printf("\nplease input the information:\n");
				scanf("%s", name);
		    	scanf("%d", &number);
		    	if (number == 0)
			    	break;
            	if(judge(head,number,name))
            	{
		       		s = (Node*)malloc(sizeof(Node));
		        	strcpy(s->name, name);
		        	s->number = number;
			    	s->next = p->next;
			    	p->next = s;
                	printf("sorted!\n");
				}
				else
                	printf(" repeated!\n");
			}
			else
				printf("can't find this position!\n");
			printf("insert continue?(y/n):");
			getchar();
			scanf("%c",&ok);
	    }while(ok=='y');
    }
	getchar();
}

/*添加学生信息*/
void Add(LinkList head)
{
    char name[20];
    int number;
	char ok;
	Node* p=head, * s;
    OK;
    if(e=='c'||e=='C')
    {
		while (p && p->next)//每次都添加到当前学生信息到末尾
			p = p->next;
		if (p)
		{	
			do
			{
				printf("please input the imformation:\n");
				scanf("%s", name);
				scanf("%d", &number);
				if (number == 0)
					break;
				if(judge(head,number,name))
				{
					s = (Node*)malloc(sizeof(Node));
					strcpy(s->name, name);
					s->number = number;
					p->next = s;
					s->next = NULL;
					printf("added!\n");
					p=p->next;
				}
				else
					printf(" repeated!\n");
				printf("add continue?(y/n):");
				getchar();
				scanf("%c",&ok);
			}while(ok=='y');
		}
		else printf("add failed!\n");
	}
	getchar();
}

/*删除学生信息*/
void Delete(LinkList head)
{
	Node* p=head, * q;
	int j,pos;
	char ok;
	if(p==NULL||p->next==NULL)
	{
		printf("there is nothing to delete!\n");
		getchar();
		return;
	}
    OK;
    if(e=='c'||e=='C')
    {
		do
		{
			p=head;
			j=0;
			printf("please input the position:");//要删除的学生位置
			scanf("%d", &pos);
			while (j < pos - 1 && p)                          
			{
				p = p->next;
				j++;
			}
			if (p == NULL || p->next == NULL)
				printf("\nthe pos is ERROR!\n\n");
			else
			{
				q = p->next;
				p->next = q->next;
				free(q);
				printf("\n********delete already********\n\n");
			}
			printf("delete continue?(y/n):");
			getchar();
			scanf("%c",&ok);
		}while(ok=='y');
    }
	getchar();
}

/*输出学生信息*/
void OutPut(LinkList head)
{
	Node* p;
	p = head->next;  
	if(!p)
		printf("nothing!\n\n");
	else
	{
		printf("\n********the informations are********\n");
		while (p)
		{
			printf("name: %s\n", p->name);
			printf("id: %d\n\n", p->number);
			p = p->next;
		}
	}
	getchar();
}

/*保存学生信息*/
void save(LinkList head)
{
    Node*p=head;
    FILE*fp;
    char filename[40];
    if(p==NULL||p->next==NULL)
	{
		printf("there is nothing to save!\n");
		getchar();
		return;
	}
    OK;
    if(e=='c'||e=='C')
    {
		printf("please input the filename:");
		getchar();
		gets(filename);
		if((fp=fopen(filename,"a"))==NULL)//创建一个.txt文件来保存当前学生信息
		{
			printf("can't open it!\n");
			getchar();
			return;
		}
		printf("opened!\n");
		getchar();
		for(p=head->next;p;p=p->next)
			fprintf(fp,"%10s%10d\n",p->name,p->number);
		printf("saved!\n");
		getchar();
		fclose(fp);
    }
}

/*写入新文件*/
void write(LinkList head)
{
    Node*p;
    FILE*fp;
    char filename[40];
    OK;
    if(e=='c'||e=='C')
    {
		printf("please input the filename:");//若文件已经存在则会覆盖此文件
		getchar();
		gets(filename);
		if((fp=fopen(filename,"w"))==NULL)
		{
			printf("can't open it!\n");
			getchar();
			return;
		}
		printf("opened!\n");
		getchar();
		for(p=head->next;p;p=p->next)
			fprintf(fp,"%10s%10d\n",p->name,p->number);
		printf("saved!\n");
		getchar();
		fclose(fp);
    }
}

/*读取文件*/
void read()
{
    FILE*fp;
    char ch;
    char filename[40];
    OK;
    if(e=='c'||e=='C')
    {
		printf("please input the filename:");
		getchar();
		gets(filename);
		if((fp=fopen(filename,"r"))==NULL)
		{
			printf("there is no \"%s\"!\n",filename);
			getchar();
			return;
		}
		printf("opened!\n");
		getchar();
		while ((ch = getc(fp)) != EOF) 
			putc(ch, stdout); //行缓冲,换行时输出
		fclose(fp);
    }
    getchar(); 
}

/*查找学生信息*/
void Search(LinkList head)
{
	char name[20];
	char ok;
    Node*p=head;
    if(p==NULL||p->next==NULL)
	{
		printf("there is nothing to search!\n");
		getchar();
		return;
	}
    OK;
    if(e=='c'||e=='C')
    {
		do
		{
			printf("please input the name:");
			scanf("%s", name);
			p = head->next;
			while (p)
			{
				if (strcmp(p->name, name) != 0)
					p = p->next;
				else
					break;
			}
			if (p == NULL)
				printf("can't find it!\n\n");
			else
			{
				printf("--------the information is--------\n");
				printf("name: %s\n", p->name);
				printf("id: %d\n", p->number);
			}
			printf("search continue?(y/n):");
            getchar();
			scanf("%c",&ok);
		}while(ok=='y');
    }
	getchar();
}

/*学生总人数*/
void ListLength(LinkList head)
{
	int count = 0;
	Node* p = head->next;
	while (p)
	{
		count++;
		p = p->next;
	}
	printf("\nlength=%d\n\n", count);
	getchar();
}

/*交换姓名*/
void swapname(char *a,char*b)
{
	char c[20];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
}

/*交换序号*/
void swapid(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

/*以学号排序*/
void Sort(LinkList head)
{
	Node*p=head->next,*t;
	int choice;
	if(p==NULL||p->next==NULL)
	{
		printf("there is nothing to sort!\n");
		getchar();
		return;
	}
    OK;
    if(e=='c'||e=='C')
    {
		printf("choose:\n");
		printf("1.low->high. 2.high->low.\n");//可从小到大也可以从大到小排
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(p!=NULL&&p->next!=NULL)
					{
						for(p=head->next;p->next;p=p->next)
						{
							for(t=p->next;t;t=t->next)
							{
								if(p->number>t->number)
								{
									swapname(p->name,t->name);
									swapid(&p->number,&t->number);
								}
							}
						}
						printf("sorted!\n");
					}
					else printf("error!\n");
					break;
			case 2:if(p!=NULL&&p->next!=NULL)
					{
						for(p=head->next;p->next;p=p->next)
						{
							for(t=p->next;t;t=t->next)
							{
								if(p->number<t->number)
								{
									swapname(p->name,t->name);
									swapid(&p->number,&t->number);
								}
							}
						}
						printf("sorted!\n");
					}
					else printf("error!\n");
					break;
			default:printf("please make the right choice!\n");break;
		}
    }
	getchar();
}

/*修改学生信息*/
void Modify(LinkList head)
{
	int choice,id,number1;
	char name1[20];
	char ok;
    Node*p=head;
    if(p!=NULL&&p->next!=NULL)
    {
        OK;
        if(e=='c'||e=='C')
        {
            do
            {
                p=head;
			    OutPut(head);
			    printf("please input the id:");
			    scanf("%d",&id);
				while (p)
				{
					if (p->number != id)
						p = p->next;
					else
						break;
				}
				if(p==NULL)
				{
					printf("inexistence!\n");
					continue;
				}
			    printf("\n1.change the id.\n");//修改学号
			    printf("2.change the name.\n");//修改姓名
			    printf("3.all change.\n");//都修改
			    printf("make the choice:");
			    scanf("%d",&choice);
			    switch(choice)
			    {
				    case 1:printf("please input the new id:");
					    scanf("%d",&number1);
						if(judge_id(head,number1))
						{
							for(p=head->next;p;p=p->next)
							{
								if(id==p->number)
								{
									p->number=number1;
									printf("id changed!\n");
									break;
								}
							}
						}
                        break;
                    case 2:printf("please input the new name:");
                        scanf("%s",&name1);
						if(judge_name(head,name1))
						{                    
							for(p=head->next;p;p=p->next)
							{
								if(id==p->number)
								{
									strcpy(p->name,name1);
									printf("name changed!\n");
									break;
								}
							}
						}
                        break;
                    case 3:printf("please input the name and the number:");
                        scanf("%s %d",name1,&number1);
						if(judge(head,number1,name1))
						{
							for(p=head->next;p;p=p->next)
							{
								if(id==p->number)
								{
									p->number=number1;
									strcpy(p->name,name1);
									printf("all changed!\n");
									break;
								}
							}
						}
						else printf(" repeated!\n");
                        break;
                    default:printf("please make the right choice!\n");break;
                }
                printf("modify continue?(y/n):");
                getchar();
                scanf("%c",&ok);
            }while(ok=='y');
        }
    }
    else 
	{
        printf("there is nothing to change!\n");
		getchar();
		return;
	}
	getchar();
}

/*删除当前所有学生信息*/
void Clear(LinkList head)
{
    Node* p=head,*q;
    if(p==NULL||p->next==NULL)
	{
		printf("there is nothing to clear!\n");
		getchar();
		return;
	}
    OK;
    if(e=='c'||e=='C')
    {
        p=head->next;
        while(p)  
        {
            q = p->next;
            free(p);
            p = q;
        }
        head->next = NULL;
        printf("cleared!\n");
    }
	getchar();
}

/*主函数*/
void main()
{
	Node* p;
    char op,flag;
    int cnt=0,jk=0;
    char name[20],pass[20];
	LinkList ha;
	ha = InitList();
    while(cnt<4)
    {
        printf("\nPlease input MY's password:");//输入用户密码(四次机会)
        gets(pass);
        if(!strcmp(pass,"4444"))
        {
            printf("\n\n ****Welcome To The Student Management System****\n\n");
			printf("         please press \"enter\" to continue\n\n");
	        while (1)
	        {
                getchar();
				printf("------------------------------\n");
		        printf("1.creatbyrear.\t");
		        printf("2.creatbyhead.\n");
		        printf("3.insert.\t");
		        printf("4.add.\n");
		        printf("5.delete.\t");
		        printf("6.search.\n");
		        printf("7.sort.\t\t");
		        printf("8.length.\n");
		        printf("9.output.\t");
			    printf("0.modify.\n");
				printf("c.clear.\t");
		        printf("q.quit.\n");
                printf("s.save.\t\t");
                printf("r.read.\n");
                printf("w.write.\n");
				printf("------------------------------\n");
		        printf("\nmake the choice:");
		        scanf("%c", &flag);
		        switch (flag)
		        {
		            case '1':CreatByRear(ha);
			            break;
		            case '2':CreatByHead(ha);
			            break;
		            case '3':Insert(ha);
			            break;
		            case '4':Add(ha);
			            break;
		            case '5':Delete(ha);
			            break;
		            case '6':Search(ha);
			            break;
		            case '7':Sort(ha);
			            break;
		            case '8':ListLength(ha);
			            break;
		            case '9':OutPut(ha);
			            break;
			        case '0':Modify(ha);
				        break;
					case 'c':Clear(ha);
						break;
		            case 'q':printf("make sure you already saved all fils before quit?(y/n):");//提示保存当前信息到文件
                        getchar();
                        scanf("%c",&op);
                        if(op=='y')
                        {
                            jk=1;
                            printf("\nexit!\n\n");
                        }
                        else if(op=='n');
                        else printf("please make the right choice!\n");
			            break;
                    case 's':save(ha);
                        break;
                    case 'r':read(ha);
                        break;
                    case 'w':write(ha); 
                        break;
		            default:printf("please make the right choice!\n");
			            getchar();
			            break;
		        }
                if(jk) break;
            }
            if(jk) break;
	    }
        if(cnt<3)
        {
            printf("wrong password! you only have %d chances!\n",(3-cnt));
            cnt++;
        }
        else 
        {
            printf("you have no chance!\n");
            break;
        }
    }
}