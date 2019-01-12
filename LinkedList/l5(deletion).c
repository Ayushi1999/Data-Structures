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
void addAtBeg(struct node** h,int d)
{
    struct node* nn=createNode();
    nn->data=d;
    nn->next=*h;
    *h=nn;
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
    //curr=(struct node*)malloc(sizeof(struct node*));
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=nn;
    }
}
void deleteAtBeg(struct node** h)
{
    if(*h==NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
  struct node* temp=*h;
  *h=(*h)->next;
  //int x=temp->data;
  free(temp);
  temp=NULL;
    }
    while((*h)!=NULL)
    {
        printf("%d ",(*h)->data);
        *h=(*h)->next;
    }
}
void deleteAtLast(struct node **h)
{
     if(*h==NULL)
     {
         printf("list is empty");
     }
     else
     {
         struct node* curr=(struct node*)malloc(sizeof(struct node*));
         while(curr&&curr->next&&(curr->next)->next)
         {
             curr=curr->next;
         }
         free((curr->next)->next);
       curr->next=NULL;
     }
}
int main()
{
    struct node* head=NULL;
//    head=(struct node*)malloc(sizeof(struct node*));
    int i,data;
    for(i=0;i<5;i++)
    {
        scanf("%d",&data);
       // addAtBeg(&head,data);
           addAtLast(&head,data);
    }
  //  head->data=10;
    //deleteAtBeg(&head);
    deleteAtLast(&head);
    return 0;
}
