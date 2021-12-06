typedef char Type; 
#define MAX 44

/*二叉树的结构定义*/
typedef struct BitNode
{
    Type data;
    struct BitNode*left,*right;
}BitNode,*BiTree;

/*二叉树的建立*/
void CreatBiTree(BiTree *T)
{
    Type ch,s[MAX];
    int k=0;
    scanf("%c",&ch);
    ch=s[i++];
    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BitNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch;
        CreatBitree(&(*T)->left);
        CreatBitree(&(*T)->right);
    }
}

/*前序*/
void PreorderTravers(BiTree T)
{
    if(!T)
        return;
    printf("%c ",T->data);
    PreorderTravers(T->left);
    PreorderTravers(T->right);
}

