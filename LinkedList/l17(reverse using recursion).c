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
struct node* reverse(struct node** h)
{
    struct node* first;
    struct node* second;//=(struct node*)malloc(sizeof(struct node*));
    struct node* curr;//=(struct node*)malloc(sizeof(struct node*));
    first=*h;
    if(first)
    {
       second=first->next;
    }
    if(second==NULL)
    {
        return first;
    }

    curr=reverse(&second);
     // printf("Ffff");
    first->next->next=first;
    first->next=NULL;
     *h=curr;
    return curr;

}
void print(struct node** h)
{
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
reverse(&head);
print(&head);
//printf("%d ",c->data);
}
