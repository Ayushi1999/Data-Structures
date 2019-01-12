#include<iostream>
stack<int>s;
typedef struct stack
{
int top;
char *arr;
}ss;
struct stack createStack()
{
    struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
    s1->top=-1;
    s1->arr=(struct stack*)malloc(sizeof(struct stack));
};
int isFull(stack stack* mem)
{
    int x=5;
    if(mem->top==x)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void insert(struct stack** mem,int ele)
{
    if(isFull(*mem))
    {
        printf("values cannot be inserted")
    }
    else
    {
        *mem->top=(*mem)->top+1;
        *mem->arr[(*mem)->top]=ele;
    }
}
char pop(struct stack* mem)
{
    return mem->arr[mem->top--];
}
struct stack* peek(struct stack* mem)
{
    return mem->arr[mem->top];
};
void fun(struct stack *mem,char[] str)
{
    int i;
    if(str.length%2!=0)
    {
        return 0;
    }
    for(i=0;i<str.length;i++)
    {
        if(mem->arr[mem->top]=='{'||mem->arr[mem->top]=='['||mem->arr[mem->top]=='(')
            insert();
        if(mem->arr[mem->top]=='}')
        {
            if(peek(mem)=='{')
                pop(mem);
        }
        if(mem->arr[mem->top]==']')
        {
            if(peek(mem)=='[')
                pop(mem);
        }
        if(mem->arr[mem->top]=='(')
        {
            if(peek(mem)==')')
                pop(mem);
        }
    }
}
int main()
{
struct stack *stk=createStack();
int ele,ch;
int i;
char str[100];
for(i=0;i<3;i++)
{
scanf("%c",str[i]);
insert(&stk,str[i]);
}
fun(&stk,str);
}
