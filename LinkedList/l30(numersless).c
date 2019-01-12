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
    struct node* curr=*h;
    if(curr == NULL)
    {
        nn->data=data;
        nn->next=NULL;
        *h=nn;
    }
    else
    {
        nn->data=data;
        nn->next=NULL;

        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=nn;
    }
}
struct node* NumbersRemove(struct node* h,int x)
{
    struct node* result=NULL;
      if(h==NULL)
        return result;
        else if(h->data>=x)
        {
            result=h;
            result->next=NumbersRemove(h->next,x);
        }
       else
        {
           NumbersRemove(h->next,x);
        }
}
int main()
{
    struct node* head=NULL;
    int data,i,x;
    for(i=0;i<5;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    scanf("%d",&x);
    head=NumbersRemove(head,x);
   while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    return 0;
}
