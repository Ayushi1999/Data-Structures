#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int *arr;
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
    ss->arr=(int*)malloc(sizeof(int)*50);
    return ss;
};
void push(struct stack* mem,int ele)
{
    (mem)->top=(mem)->top+1;
    (mem)->arr[(mem)->top]=ele;
}
int pop(struct stack* mem)
{
    return (mem)->arr[(mem)->top--];
}
int isEmpty(struct stack *mem)
{
    if(mem==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void GreaterElement(struct stack *stk,int arr[])
{
  //  printf("kkk");
    push(stk,arr[0]);
  //  printf("oo");
    int i;
    int next,x;
    for(i=1;i<11;i++)
    {
         next=arr[i];
        if(isEmpty(stk)==0)
        {
             x=pop(stk);
                while(x<next)
                {
                    printf("%d ",next);   //5 3 2 10 6 8 1 4 12 7 4
                   if(isEmpty(stk)==1)
                       break;
                    x=pop(stk);
                }
                if(x>next)
                    push(stk,x); //10
        }
        push(stk,next);//stack =  12 7 4
    }
//printf("%d",isEmpty(stk));
                while(isEmpty(stk)==0)
                {
                 //   printf("ll");
                x=pop(stk);
                next=-1;
                printf("%d ",next);
                }
}
int main()
{
    struct stack* stk=createStack();
    int arr[]= {11, 13, 21, 3};   //13,21,-1,-1
    GreaterElement(stk,arr);
    return 0;
}
