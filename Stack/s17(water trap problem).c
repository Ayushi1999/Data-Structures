#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int arr[100];
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
  //  ss-arr=(int*)malloc(sizeof(int)*10000);
    return ss;
};
void push(struct stack *stk,int x)
{
    stk->top=stk->top+1;
    stk->arr[stk->top]=x;
}
int pop(struct stack* stk)
{
    return stk->arr[stk->top--];
}
int top(struct stack* stk)
{
    return stk->arr[stk->top];
}
int min(int a,int b)
{
    return a>b?b:a;
}
int isEmpty(struct stack* stk)
{
    if(stk->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void WaterTrap(struct stack* stk,int a[])
{
    int i;
    int water=0;
    int distance,height;
    for(i=0;i<6;i++)
    {
        while(!isEmpty(stk)&&a[i]>=a[top(stk)])
        {
            int x=top(stk);
            pop(stk);
            if(isEmpty(stk))
                break;
            distance=i-top(stk)-1;
            height=min(a[i],a[top(stk)])-a[x];
            water+=distance*height;
        }
        push(stk,i);
    }
    printf("%d",water);
}
int main()
{
    struct stack* s1=createStack();
    int arr[]={3,0,0,2,0,4};
    WaterTrap(s1,arr);
}
