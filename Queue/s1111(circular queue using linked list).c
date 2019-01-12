#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct queue
{
    struct node* front;
    struct node* back;
};
struct queue* initialize()
{
    struct queue* qq=(struct queue*)malloc(sizeof(struct queue));
    qq->front=NULL;
    qq->back=NULL;
    return qq;
}
struct node* newnode(int data)
{
    struct node* n1=(struct node*)malloc(sizeof(struct node));
    n1->data=data;
    n1->next=NULL;
    return n1;
}
void enqueue(struct queue* q1,int data)
{
    struct node* nn=newnode(data);
    if(q1->back == NULL)
    {
        q1->back=nn;
        q1->front=nn;
    }
    else
    {
        q1->back->next=nn;
    }
    q1->back=nn;
    q1->back->next=q1->front;
}
int dequeue(struct queue* qq)
{
    if(qq->front == qq->back)
    {
        int x=qq->front->data;
        qq->front=qq->back=NULL;
        return x;
    }
    else
    {
        struct node* temp = qq->front;
        int x=temp->data;
        qq->front=qq->front->next;
        qq->back->next=qq->front;
        free(temp);
        return x;
    }
}
int main()
{
    struct queue* q1=initialize();
    enqueue(q1,10);
    enqueue(q1,20);
    printf("%d",dequeue(q1));
    return 0;
}

