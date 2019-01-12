#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *arr;
    int top;
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->arr = (int*)malloc(sizeof(int)*10000);
    ss->top = -1;
    return ss;
}
void push(struct stack** ss,int item)
{
    (*ss)->top = (*ss)->top+1;
    (*ss)->arr[(*ss)->top] = item;
}
void pop(struct stack* ss)
{
    ss->arr[ss->top--];
}
int peek(struct stack* ss)
{
    return ss->arr[ss->top];
}
int isEmpty(struct stack* ss)
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
int MaxArea(int *a,int n)
{
    struct stack* stk = createStack();   //area is due to left and right bars present.
    int max=0,i;
    int area;
    push(&stk,0);
    //printf("bnmnb");
    for(i=1;i<n;)
    {
       // printf("pppp");
        if(isEmpty(stk)||a[i]>=a[peek(stk)])
        {
            push(&stk,i++);
        }
        else
        {
            int x=peek(stk);
            pop(stk);
            area=isEmpty(stk)?a[x]*i:a[x]*(i-peek(stk)-1);
            if(max<area)
            {
                max=area;
            }
        }
    }
    while(!isEmpty(stk))
    {
        int y=peek(stk);
            pop(stk);
            area=isEmpty(stk)?(a[y]*i):(a[y]*(i-peek(stk)-1));
            if(max<area)
            {
                max=area;
            }
    }
    return max;
}
int main()
{
    int a[1000];
    int i;
    for(i=0;i<7;i++)
    {
        scanf("%d",&a[i]);
    }
    int max1=MaxArea(a,7);
    printf("%d",max1);
    return 0;
}
