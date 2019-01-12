#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *arr;
    int front;
    int back;
};
struct queue* createQueue()
{
    struct queue *qq=(struct queue*)malloc(sizeof(struct queue));
    qq->arr=(int*)malloc(sizeof(int)*10000);
    qq->front=-1;
    qq->back=-1;
    return qq;
}
void enqueue(struct queue** qq,int data,int n)
{
    if((*qq)->back=n-1&&(*qq)->front==0)
    {
        printf("full");
    }
    else if((*qq)->front==-1&&(*qq)->back==-1)
    {
        (*qq)->front++;
        (*qq)->back++;
        (*qq)->arr[(*qq)->back]=data;
    }
    else if((*qq)->back==n-1&&(*qq)->front!=0)
    {
        (*qq)->back=0;
        (*qq)->arr[(*qq)->back]=data;
    }
    else
    {
        (*qq)->back++;
        (*qq)->arr[(*qq)->back]=data;
    }
}
void dequeue(struct queue* qq,int n)
{
    if(qq->front==-1&&qq->back==-1)
    {
        printf("element cannot be deleted");
    }
    else if(qq->front==qq->back)
    {
        qq->front++;
        qq->back++;
    }
    else if(qq->front==n-1)
    {
        qq->arr[qq->front++]%(n-1);
    }
    else
    {
        qq->arr[qq->front++];
    }
}
void print(struct queue* qq)
{
    int i;
    if(qq->front<qq->back)
    {
        for(i=qq->front;i<=qq->back;i++)
        {
            printf("%d ",qq->arr[i]);
        }
    }
    else
    {
        int i;
        for(i=0;i<qq->back;i++)
        {
            printf("%d ",qq->arr[i]);
        }
        for(i=qq->front;i<5;i++)
        {
            printf("%d ",qq->arr[i]);
        }
    }
}
int main()
{
    struct queue* q2=createQueue();
    int i;
    for(i=1;i<=5;i++)
    {
    enqueue(&q2,i,5);
    }
    print(q2);
    dequeue(q2,5);
}
