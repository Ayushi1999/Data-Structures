#include<stdio.h>
#include<stdlib.h>
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
};
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
      //  curr=(struct node*)malloc(sizeof(struct node*));
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=nn;
    }
}
void findNode(struct node* h1,int pos)
{
    int count=0,i=0;
    struct node* curr1=h1;
    while(curr1->next!=NULL)
    {
        count++;
        curr1=curr1->next;
    }
    curr1=h1;
    //curr1=(struct node*)malloc(sizeof(struct node*));
    while(i<count-pos+1)
    {
        //i++;
        curr1=curr1->next;
        i++;
    }
    printf("%d",curr1->data);
}
int main()
{
    struct node* head=NULL;
    int i,data,pos;
    for(i=0;i<5;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    scanf("%d",&pos);
    findNode(head,pos);
    return 0;
}
