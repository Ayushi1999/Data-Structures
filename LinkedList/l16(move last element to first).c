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
    if(*h==NULL)
    {
        nn->data=data;
        nn->next=NULL;
        *h=nn;
    }
    else
    {
        struct node* curr=*h;
        nn->data=data;
        nn->next=NULL;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=nn;
    }
}
void MoveAtFront(struct node** h,int data)
{
    struct node* last,*prev;
    struct node* curr=*h;
    while(curr&&curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    last=prev->next;
    prev->next=NULL;
    last->next=*h;
    *h=last;

    while((*h)!=NULL)
    {
         //printf("Xxxx");
        printf("%d ",(*h)->data);
        (*h)=(*h)->next;
    }
}
int main()
{
struct node* head=NULL;
int i,data,n;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&data);
    addAtLast(&head,data);
}
MoveAtFront(&head,data);
return 0;
}
