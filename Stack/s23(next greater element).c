#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *arr;
    int top;
};
struct stack* createStack()
{
    struct stack* ss = (struct stack*)malloc(sizeof(struct stack));
    ss->top = -1;
    ss->arr = (int*)malloc(sizeof(int)*10000);
    return ss;
};
void push(struct stack* ss,int c)
{
    (ss)->top = (ss)->top+1;
    (ss)->arr[(ss)->top] = c;
}
void pop(struct stack* ss)
{
    ss->top--;
}
int peek(struct stack* ss)
{
    return ss->arr[ss->top];
}
int empty(struct stack* ss)
{
    if(ss->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void fun(int a[],int n)
{
    int i,flag=0;
    struct stack* stk = createStack();
    push(stk,a[0]);
    for(i=1;i<n;i++)
    {
        flag = 0;
        while(!empty(stk) && peek(stk)<a[i])
        {
            printf("%d---->%d",peek(stk),a[i]);
            printf("\n");
            flag = 1;
            pop(stk);
        }
        if(flag == 0)
        {
            printf("%d---->%d",peek(stk),-1);
            printf("\n");
        }
        push(stk,a[i]);
    }
    printf("%d---->%d",a[n-1],-1);
}
int main()
{
    int a[4]={11,13,21,3};
    fun(a,4);
    return 0;
}
