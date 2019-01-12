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
    return newnode;
};
void addAtLast(struct node** h,int d)
{
    struct node* nn=createNode();
    if(*h==NULL)
    {
        nn->data=d;
        nn->next=NULL;
        *h=nn;
    }
    else
    {
        nn->data=d;
        nn->next=NULL;
        struct node* curr=*h;
      //  curr=(struct node*)malloc(sizeof(struct node*));
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=nn;
    }
}
void Middle(struct node* h1,int n)
{
    int count=0,i;
    struct node* curr1=h1;
    struct node* curr2=h1;
    if(h1!=NULL)
    {
    while((curr1!=NULL)&&(curr2->next!=NULL))
    {
        curr1=curr1->next;
        curr2=curr2->next->next;
    }
    printf("%d",curr1->data);
    }

   /* while(curr1->next!=NULL)
    {
        count++;
        curr1=curr1->next;
    }
    int t;
    curr1=h1;
    if(n%2==0)
    {
         t=count/2;
         i=0;
    }
    else
    {
        t=(count/2)+1;
        i=1;
    }
    //curr1=(struct node*)malloc(sizeof(struct node*));
    while(i<t)
    {
        //i++;
        curr1=curr1->next;
        i++;
    }
    printf("%d",curr1->data);*/
}
int main()
{
    struct node* head=NULL;
    int i,data,pos,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    Middle(head,n);
    return 0;
}

