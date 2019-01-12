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
struct queue* createQueue()
{
    struct queue* qq=(struct queue*)malloc(sizeof(struct queue));
    qq->front=NULL;
    qq->back=NULL;
    return qq;
}
int isEmpty(struct queue* qq)
{
    if(qq->front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(struct queue** q1,int data)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if((*q1)->front==NULL)
    {
        (*q1)->back=(*q1)->front=nn;
    }
    else
    {
        (*q1)->back->next=nn;
       // (*q1)->back=nn;
    }
}
void delete1(struct queue* q1)
{
    struct node* qq=q1->front;
    q1->front=q1->front->next;
    free(qq);
}
void print(struct queue* qq)
{
    printf("%d ",qq->front->data);
}
int main()
{
    struct queue* qq=createQueue();
    insert(&qq,10);
    print(qq);
    //delete1(qq);
    insert(&qq,20);
    print(qq);
    insert(&qq,30);
    print(qq);
    int c=isEmpty(qq);
 //   printf("%d",c);
}
