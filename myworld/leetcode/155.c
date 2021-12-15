typedef struct MinStack{
    int data;
    struct MinStack *next;
} MinStack;

MinStack* minStackCreate() 
{
    MinStack *S = (MinStack*)malloc(sizeof(MinStack));  
    S->data = 0;                                     
    S->next = NULL;
    return S;
}

void minStackPush(MinStack* obj, int val) 
{
    MinStack *s = (MinStack*)malloc(sizeof(MinStack));  
    s->data = val;
    s->next = obj->next;
    obj->next = s;
}

void minStackPop(MinStack* obj) 
{
    MinStack *s;                                        
    if(obj->next == NULL)                             
        return ;
    s = obj->next;
    obj->next = s->next;
    free(s);                                          
}

int minStackTop(MinStack* obj) 
{
    return obj->next->data;
}

int minStackGetMin(MinStack* obj) 
{
    MinStack *p = obj->next;
    int min = p->data;                                 
    while(p != NULL)
    {                                   
        if(p->data < min)                               
            min = p->data;
        p = p->next;
    }
    return min;
}

void minStackFree(MinStack* obj) 
{                      
    MinStack *p = obj;
    MinStack *s;
    while(p != NULL)
    {
        s = p->next;
        free(p);
        p = s;
    }
}