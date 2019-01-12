#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct stack
{
    int *arr;
    int top;
}s1;
struct stack* createStack()
{
    struct stack *ss=(struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
    ss->arr=(int*)malloc(sizeof(int)*1000);
    return ss;
}
/*void initialize(struct stack *mem,int x)
{
      mem->arr=(int*)malloc(x*sizeof(int));
      mem->top=-1;
}*/
int isEmpty(struct stack *mem)
{
    if(mem->top==-1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *mem)
{
    int x=2;
    if(mem->top==x)
        return 1;
    else
        return 0;
}
int pop(struct stack* mem)
{
    return mem->arr[mem->top--];
}
void insert(struct stack *mem,int ele)
{
    int element;
    if(isFull(mem))
    {
        printf("element cannot be inserted");
    }
    else
    {
       mem->top=mem->top+1;
       // scanf("%d",&element);
        (mem)->arr[(mem)->top]=ele;
     //   printf("%d",mem->arr[mem->top]);
    }
    //print(mem);
}
void print(struct stack *mem)
{
    printf("%d\n",mem->arr[mem->top]);
}
int main()
{
   // s1 *stk=(s1*)malloc(sizeof(s1));
    //initialize(stk,SIZE);
    struct stack* stk=createStack();
 //   int c=isEmpty(stk);
  //  printf("%d\n",c);
    int i;
    insert(stk,10);
   // pop(stk);
    //printf("%d",c1);
    print(stk);
    insert(stk,20);
    print(stk);
    //int d=isFull(stk);
    //printf(" %d",d);
}
