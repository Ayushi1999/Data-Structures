#include<stdio.h>
#include<stdlib.h>
struct stack
{
    struct node* top;
};
struct node
{
    int data;
    struct node* next;
};
struct stack* createStack()
{
    struct stack* s1=(struct stack*)malloc(sizeof(struct stack));
    s1->top=NULL;
  //  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  //  s1->top->next=NULL;
    return s1;
}
void push(struct stack* ss,int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        return;
    else
    newnode->data=x;
    newnode->next=ss->top;
    ss->top=newnode;
}
void print(struct stack* ss)
{
    printf("%d ",ss->top->data);
}
void pop(struct stack* ss)
{
  //  struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=ss->top;
    ss->top=ss->top->next;
    free(temp);
}
int isEmpty(struct stack* s1)
{
    if(s1->top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack* ss=createStack();
    push(ss,10);
    print(ss);
    push(ss,20);
    print(ss);
    pop(ss);
    pop(ss);
    int x=isEmpty(ss);
    printf("%d",x);
}
