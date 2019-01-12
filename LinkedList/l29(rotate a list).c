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
/*void reverse(struct node* h)
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
}*/
void fun(struct node* h,int k)
{
    int p=1;
    struct node* curr=h;
    struct node* temp;
    struct node* temp1;
    struct node* temp2;
  /*  while(p<k&&curr!=NULL)
    {
        //8t=curr;
        curr=curr->next;
        p++;
    }
    temp=curr;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=h;
    h=temp->next;
    temp->next=NULL;*/
    //printf("Sssss");
   // printf("Ssssssssssddddddddddddd");
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
    int k;
    for(i=0;i<6;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    scanf("%d",&k);
    fun(head,k);
}

