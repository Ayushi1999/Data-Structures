#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createNode()
{
   struct node* newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   return newnode;
};
void insertAtBeg(struct node* n,int data)
{
     struct node* newnode=createNode();
     newnode->data=data;
     newnode->next=n;
     n=newnode;
     while(newnode!=0)
     {
         printf("%d ",newnode->data);
         newnode=newnode->next;
     }
}
int main()
{
    struct node* head;
    struct node* second;
    int data;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&data);
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=NULL;
    insertAtBeg(head,data);
    return 0;
}

