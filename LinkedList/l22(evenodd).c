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
       while(curr->next!=NULL)
       {
           curr=curr->next;
       }
       curr->next=nn;
    }
}
void evenodd(struct node** h,int data)
{
 struct node* estart=NULL;
 struct node* eend=NULL;
 struct node* ostart=NULL;
 struct node* oend=NULL;
 struct node* curr=*h;
 while(curr!=NULL)
 {
     int c=curr->data;
     if(c%2==0)
     {
         if(estart=NULL)
         {
             estart=curr;
             eend=estart;
         }
         else
         {
             eend->next=curr;
             eend=eend->next;
         }
     }
     else
     {
         if(ostart=NULL)
         {
             ostart=curr;
             oend=ostart;
         }
         else
         {
             oend->next=curr;
             oend=oend->next;
         }
     }
     curr=curr->next;
 }
     if(eend==NULL||oend==NULL)
        return;
     eend->next=ostart;
     oend->next=NULL;
     while((*h)!=NULL)
    {
        printf("%d",(*h)->data);
        (*h)=(*h)->next;
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
    evenodd(&head,data);
    //print(head);
    return 0;
}
