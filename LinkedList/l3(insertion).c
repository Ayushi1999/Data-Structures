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
 //printf("fghjk ");
 return newnode;
};
void insertAtMid(struct node* n,int d,int pos)
{
   // printf("ghjk ");
    struct node* curr;
    curr=(struct node*)malloc(sizeof(struct node*));
    struct node* nn=createNode();
    //nn->data=data;
    int p=1;
    curr=n;
    while(p<pos)
    {
        curr=curr->next;
        p++;
    }
    if(curr==NULL)
    {
        printf("Node cannot be inserted");
    }
    else
    {
       // printf("fghj ");
   //     struct node *nn=createNode();
        nn->data=d;
        nn->next=curr->next;  //means newnode is pointing to address of nextnode
        curr->next=nn;    //curren node is pointing to address of newnode
    //    printf("fgh ");
    //    nn->next=;
    }
    //printf("ghj ");
    while(n!=0)
    {
        printf("%d ",n->data);
        n=n->next;
    }
}
void insertAtBeg(struct node** n,int data)
{
     struct node* newnode=createNode();

     newnode->data=data;
     newnode->next=*n;
     *n=newnode;
     /*while(n!=0)
     {
         printf("%d ",n->data);
         n=n->next;
     }*/
     // printf("%d ",(*n)->data);
}
void insertAtLast(struct node** h1,int data)
{
       struct node* newnode=createNode();
    if(*h1==NULL)
    {
        newnode->data=data;
    newnode->next=NULL;
       // addAtBeg(&h1,data);
       *h1=newnode;
    }
    else
    {
    newnode->data=data;
    newnode->next=NULL;
    struct node* curr=*h1;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=newnode;
    }
}
int main()
{
    struct node* head=NULL;
    int data,pos;
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&data);
        insertAtLast(&head,data);
    }
    scanf("%d",&data);
    scanf("%d",&pos);
    insertAtMid(head,data,pos);
    return 0;
}
