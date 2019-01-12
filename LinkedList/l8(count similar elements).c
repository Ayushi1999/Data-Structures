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
int count1(struct node* h1,int p1)
{
  struct node* curr=h1;
  static int count;
  if(h1==NULL)
    return count;
  if(curr->data==p1)
    count++;
  count1(curr->next,p1);
 /* while(curr!=NULL)
  {
      if(curr->data==p1)
      {
          count++;
      }
      curr=curr->next;
  }
  printf("%d",count);*/
}
int main()
{
    struct node* head=NULL;
    int i,data,p,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    scanf("%d",&p);
    int c=count1(head,p);
    printf("%d",c);
    return 0;
}


