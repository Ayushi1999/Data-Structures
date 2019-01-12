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
void swapNodes(struct node** h)
{
   struct node* prev=*h;
   struct node* curr=(*h)->next;
  /* struct node* temp=(struct node*)malloc(sizeof(struct node*));
  //  *h = curr;
   while(1)
   {
   temp=curr->next;
   curr->next=prev;
   *h = curr;
   if(temp==NULL ||temp->next==NULL)
   {
       prev->next=temp;
       break;
   }
   prev->next=temp->next;
   prev=temp;
   curr=prev->next;
   }
   while((*h)!=NULL)
   {
       printf("%d ",(*h)->data);
       (*h)=(*h)->next;
   }*/
   int temp;
   while(1)
   {
   temp=prev->data;
   prev->data=curr->data;
   curr->data=temp;
   prev=prev->next->next;
   curr=curr->next->next;
   if(curr==NULL){
    break;
   }
   }
}
void display(struct node *h){
 while(h!=NULL)
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
    swapNodes(&head);
    display(head);
}

