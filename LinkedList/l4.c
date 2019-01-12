#include<stdio.h>
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
void insertAtMid(struct node* n,int data,int pos)
{
    struct node* curr;
    curr=(struct node*)malloc(sizeof(struct node*));

    struct node* nn=createNode();
    nn->data=data;

    int p=1;
    curr=n;
    while(p<pos)
    {
        curr=curr->next;
        p++;
    }
    if(curr=NULL)
    {
        printf("Node cannot be inserted");
    }
    else
    {
        struct node *nn=createNode();
        nn->data=data;
        curr->next=nn;
        nn=curr;
    }
  /*  while(n!=0)
    {
        printf("%d ",n->data);
        n=n->next;
    }*/
}
int main()
{
    struct node* head=NULL;
  //  struct node* last;
    int data,pos;
   /* for(i=0;i<last;i++)
    {
        scanf("%d",&s->data);
        s=s->next;
    }*/
    head=(struct node*)malloc(sizeof(struct node*));
    scanf("%d",&data);
    scanf("%d",&pos);
   // head->data=10;

    insertAtMid(head,data,pos);
    return 0;
}
