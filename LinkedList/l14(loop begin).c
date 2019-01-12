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
void Loopstart(struct node* h)
{
    struct node* slow=h;
    struct node* fast=h;
    int count=0,p=0,c=0;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        c++;
        if(slow==fast)
        {
            //curr=slow->data;
            break;
        }
    }
    struct node* curr=slow->next;
    while(curr!=slow)
    {
        count++;
        curr=curr->next;
    }
    int c1=count-c;
    printf("%d",c1);
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
head->next->next->next->next->next=head->next;
Loopstart(head);
}
