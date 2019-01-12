#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
struct node* createNode()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node*));
    return newnode;
};
void addAtLast(struct node** h,int data)
{
    struct node* nn=createNode();
if(*h==NULL)
{
    nn->data=data;
    nn->next=NULL;
    *h=nn;
}
else
{
    nn->data=data;
    nn->next=NULL;
    struct node* curr=*h;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=nn;
}
//printf("%d ",nn->data);
}
void reversePrint(struct node* ptr)
{
//struct node* ptr=h;
    if(ptr==NULL)
    {
        return ;
    }
    else
    {
        reversePrint(ptr->next);
        printf("%d\n",ptr->data);
    }
}
int main()
{
struct node* head=NULL;
int i,data;
for(i=0;i<5;i++)
{
    scanf("%d",&data);
    addAtLast(&head,data);
}
reversePrint(head);
//printf("%d ",c->data);
}
