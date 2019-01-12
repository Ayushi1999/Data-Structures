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
struct node* MergeLists(struct node* result,struct node* result1)
{
    struct node* result2=(struct node*)malloc(sizeof(struct node*));
    if(result->data<=result1->data)
    {
        result2=result;
        result2->next=MergeLists(result->next,result1);
    }
    else
    {
        result2=result1;
        result2->next=MergeLists(result1->next,result);
    }
    return result2;
}
struct node* fun(struct node* h)
{
   struct node* curr=h;
   struct node* result=(struct node*)malloc(sizeof(struct node*));
   struct node* result1=(struct node*)malloc(sizeof(struct node*));
   while(curr!=NULL)
   {
       int c=curr->data;
       if(c%2==0)
       {
           result=curr;
        //   printf("%d ",result->data);
           result->next=fun(curr->next);
       }
       else
       {
           result1=curr;
      //     printf("%d ",result1->data);
           result1->next=fun(curr->next);
       }
   }
   struct node* s=MergeLists(result,result1);
   return s;
}

int main()
{
    struct node* head=NULL;
    int data,i;
    for(i=0;i<6;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    head=fun(head);
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

