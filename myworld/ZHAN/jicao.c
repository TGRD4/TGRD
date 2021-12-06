typedef int ElemType;
#define MAXSIZE 100         //栈中元素的最大个数
typedef struct {
    ElemType data[MAXSIZE]; //存放栈中元素
    int top;                //栈顶指针
} SqStack;

void InitStack(SqStack& S){
    S->top = -1;             //初始化栈顶指针
}

bool StackEmpty(SqStack& S){
    if( S->top == -1){
        return true;
    }
    return false;
}

bool Push(SqStack* S, ElemType x){
    if( S->top == MAXSIZE - 1 ){ //栈满，报错
        return false;        
    }
    S->top ++ ;                  //栈顶指针加1
    S->data[S->top] = x;          //入栈
    return true;
}
bool Pop(SqStack* S, ElemType* x){
    if( S->top == -1 ){          //栈空，报错
        return false;
    }
    x = S->data[S->top];
    S->top --;
    return true;
}

bool GetTop(SqStack* S,ElemType* x){
    if( S->top == -1 ){          //栈空，报错
        return false;
    }
    x = S->data[S->top];
    return true;
}