#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
/*struct stack
{
    int top;
    int *arr;
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack*));
    ss->top=-1;
    ss->arr(int*)malloc(sizeof(int)*10000);
    return ss;
};*/
struct queue
{
    struct node* stack1;
    struct node* stack2;
};
void push(struct node **s,int x)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=*s;
    *s=nn;
}
void enqueue(struct queue* q,int x)
{
    push(&q->stack1,x);
}
int pop(struct node** s)
{
  //  struct node* nn=(struct node*)malloc(sizeof(struct node));
    int t=(*s)->data;
    *s=(*s)->next;
    free(*s);
    return t;
}
int dequeue(struct queue* q)
{
    while(q->stack1!=NULL)
    {
        int x=pop(&q->stack1);
        push(&q->stack2,x);
    }
   int c= pop(&q->stack2);
 //  printf("%d ",c);
   return c;
}
int main()
{
    struct queue *qq=(struct queue*)malloc(sizeof(struct queue));
    qq->stack1=NULL;
    qq->stack2=NULL;
    enqueue(qq,10);
    enqueue(qq,20);
    enqueue(qq,30);
    printf("%d ",dequeue(qq));
    printf("%d ",dequeue(qq));
    printf("%d",dequeue(qq));
}
