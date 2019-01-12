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
};
void addAtLast(struct node** h,int data)
{
    struct node* nn=createNode();

    if((*h)==NULL)
    {
        nn->data=data;
        nn->next=NULL;
        (*h)=nn;
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
}
void reverse(struct node* h)
{
   struct node* prev=NULL;
   struct node* curr=h;
   struct node* temp=NULL;
   while(curr!=NULL)
   {
       temp=curr->next;
       curr->next=prev;
       prev=curr;
       curr=temp;
   }
   h=prev;
   while(h!=0)
   {
       printf("%d ",h->data);
       h=h->next;
   }
}
int main()
{
    struct node* head=NULL;
    int data,i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
   // head->next->next->next->next->next=head;
    //detectLoop(head);
    reverse(head);
}

