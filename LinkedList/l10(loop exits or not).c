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
}
void count(struct node** s)
{
    int c=1;
    struct node* hh=*s;
    while(hh->next!=*s)
    {
        c++;
        hh=hh->next;
    }
    printf("%d",c);
}
void detectLoop(struct node* h)
{
    int i,p=0;
    struct node* slow=h;
    struct node* fast=h;
    while((slow->next!=NULL)&&(fast->next->next!=NULL))
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            p=1;
            count(&slow);
            break;
          //  printf("loop detected");
        }
    }
    if(p==1)
        printf("loop detected");
    else
        printf("not");
}
void reverse(struct node* h)
{
    struct node* temp;
    struct node* curr=h;
  //  printf("%d ",curr);
    temp=curr->next;
    //printf("%d",temp);
    curr->next=NULL;
  //  printf("%d",curr->data);
    temp->next->next=curr->next;
    printf("%d",curr->next->next->data);
    printf("%d",curr->next->data);
    curr->next=temp;
}
int main()
{
    struct node* head=NULL;
    int data,i;
    for(i=1;i<=3;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
   // head->next->next->next->next->next=head;
    //detectLoop(head);
    reverse(head);
}
