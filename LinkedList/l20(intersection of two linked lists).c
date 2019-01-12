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
void Intersection(struct node** h,struct node** h1,struct node** newhead,int data,int data1)
{
 struct node* ptr1=*h;
 struct node* ptr2=*h1;
 //struct node* ptr3;

 while(ptr1!=NULL&&ptr2!=NULL)
 {
     if(ptr1->data<ptr2->data)
     {
         ptr1=ptr1->next;
     }
     else if(ptr1->data>ptr2->data)
     {
         ptr2=ptr2->next;
     }
     else
     {
         addAtLast(newhead,ptr2->data);
         ptr1=ptr1->next;
         ptr2=ptr2->next;
     }
 }
}
int main()
{
struct node* head=NULL;
struct node* head1=NULL;
struct node* newhead=NULL;
int i,data,n,data1;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&data);
    addAtLast(&head,data);
}
for(i=0;i<n;i++)
{
    scanf("%d",&data1);
    addAtLast(&head1,data1);
}
Intersection(&head,&head1,&newhead,data,data1);
print(newhead);
return 0;
}
