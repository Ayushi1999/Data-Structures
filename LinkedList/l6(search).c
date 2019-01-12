#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createNode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
  return newnode;
}
void addAtLast(struct node** h,int d)
{
    struct node* nn=createNode();
    if(*h==NULL)
    {
    nn->data=d;
    nn->next=NULL;
    *h=nn;
    }
    else
    {
    nn->data=d;
    nn->next=NULL;
    struct node* curr=*h;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=nn;
    }
}
void length(struct node** h)
{
    int count=0;
    while(*h!=NULL)
    {
        count++;
        *h=(*h)->next;
    }
    printf("%d",count);
}
int main()
{
    struct node*head=NULL;
    int i,data;
    for(i=0;i<5;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    length(&head);
}
