#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
//int a,b;
//a=1,b=1;
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
struct node* reverseInPairs(struct node* h,int k)
{
    struct node* curr=h;
    struct node* prev=NULL;
    struct node* temp=NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
        temp=curr->next;
        curr->next=NULL;
        prev=curr;
        curr=temp;
        count++;
    }
  //  h=prev;
   // h=h->next;
  //  printf("jjjj");
    if(temp!=NULL)
    {
    h->next=reverseInPairs(temp,k);
    }
    return prev;
}
int main()
{
struct node* head=NULL;
int i,data;
int k;
for(i=0;i<6;i++)
{
    scanf("%d",&data);
    addAtLast(&head,data);
}
scanf("%d",&k);
head=reverseInPairs(head,k);
//int count=0;
while(head!=NULL)
{
    printf("%d ",head->data);
    head=head->next;
  // count++;
}
//printf("%d ",c->data);
}
