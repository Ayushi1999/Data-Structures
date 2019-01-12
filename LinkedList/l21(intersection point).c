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
void print(struct node* h)
{
   while(h!=NULL)
   {
       printf("%d ",(h)->data);
       (h)=(h)->next;
   }
  //  printf("\n");
}
void func(int d,struct node* h,struct node* h1)
{
    int i;
    struct node* current1=h;
    struct node* current2=h1;
    for(i=0;i<d;i++)
    {
        if(current1=NULL)
            return ;
        current1=current1->next;
    }
  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
    {
        printf("%d",current1->data);
       break;
    }
    else
    {
    current1= current1->next;
    current2= current2->next;
    }
  }
}
void Intersection(struct node** h1,struct node** h2)
{
    struct node* ptr1=*h1;
    struct node* ptr2=*h2;
    int count1=1,count2=1,d;
    while(ptr1->next!=NULL)
    {
        count1++;
        ptr1=ptr1->next;
    }
    while(ptr2->next!=NULL)
    {
        count2++;
        ptr2=ptr2->next;
    }
    if(count1>count2)
    {
        d=count1-count2;
        func(d,h1,h2);
    }
    else
    {
        d=count2-count1;
        func(d,h2,h1);
    }
}
int main()
{
struct node* head=NULL;
struct node* head1=NULL;
struct node* newhead=NULL;
int i,data,n,data1,n1;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&data);
    addAtLast(&head,data);
}
scanf("%d",&n1);
for(i=0;i<n1;i++)
{
    scanf("%d",&data1);
    addAtLast(&head1,data1);
}
Intersection(&head,&head1);
//printf("%d",func());
return 0;
}

