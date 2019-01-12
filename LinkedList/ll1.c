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
//printf("ddddd");
return newnode;
}
void addAtBegg(struct node** head,int data)
{
    struct node* nn=createNode();
    nn->data=data;
   // printf("dddd");
    nn->next=*head;
   // printf("ddddccccc");
    *head=nn;
}
void addAtPos(struct node** h,int d,int pos)
{
    int p = 1;
    struct node* curr = (struct node*)malloc(sizeof(struct  node*));
     curr = *h;
 //   nn->data=d;
    while(p<pos)
    {
      curr=curr->next;
      p++;
    }
    if(curr==NULL)
    {
        printf("cannot insert");
    }
    else
    {
        struct node* nn=createNode();
        nn->data=d;
        nn->next=curr->next;
        curr->next=nn;
    }
   /* while(*h!=NULL)
    {
        printf("%d ",(*h)->data);
        (*h)=(*h)->next;
    } */
    //pos=pos+1;
}
void print(struct node** head,int data)
{
    while(*head!=NULL)
    {
        printf("%d ",(*head)->data);
        (*head)=(*head)->next;
    }
}
void addAtLast(struct node** head,int data)
{
    struct node* nn=createNode();
    struct node* curr=*head;
     // printf("ddddd");
    if(curr==NULL)
    {
        nn->data=data;
        nn->next=NULL;
        *head=nn;
    }
    else
    {
        nn->data=data;
        nn->next=NULL;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=nn;
    }
}
void deleteAtBegg(struct node** h,int data)
{
    //int i;
    struct node* temp=*h;
    struct node* curr=(struct node*)malloc(sizeof(struct node*));
    curr=temp->next;
    free(temp);
    *h=curr;
}
void deleteAtPos(struct node** h,int d,int pos)
{
    struct node* curr=*h;
    struct node* t=(struct node*)malloc(sizeof(struct node*));
    int p=1;
    if(pos==0)
    {
        printf("empty list");
    }
   if(pos==1)
    {

     (*h)=(*h)->next;
     free(curr);
    }
  //  else
    //{
    while(p<pos-1)
    {
        curr=curr->next;
        p++;
    }
    t=curr->next->next;
    free(curr->next);
    curr->next=t;
}
void searchanddelete(struct node** h,int d)
{
    struct node* curr=*h;
    struct node* t;
    while(curr->next!=NULL&&curr->next->data!=d)
    {
        curr=curr->next;
    }
    t=curr->next->next;
    free(curr->next);
     curr->next=t;
}
void deleteAtEnd(struct node** h,int data,int n)
{
    struct node* curr=*h;
    struct node* t;
    if(*h==NULL)
    {
        printf("list is empty");
    }
    else if(n==1)
    {
        free(*h);
        *h=NULL;
    }
    else
    {
        while(curr->next!=NULL)
        {
            t=curr;
            curr=curr->next;
        }
        free(curr->next);
        t->next=NULL;
    }
}
int search(struct node** h,int d)
{
    struct node* curr=*h;
    int flag=0;
    while(curr!=NULL)
    {
        if(curr->data==d)
        {
            flag=1;
            break;
        }
        else
        {
        curr=curr->next;
        }
    }
    return flag;
}
void reverse(struct node** hh,int data)
{
    struct node* curr=*hh;
    struct node* prev=NULL;
    struct node* temp;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    *hh=prev;
}
int main()
{
int i,data,pos,d,n;
struct node* head=NULL;//gdb   // gcc -g abc.c     //./a.out   //(gdb) b main  //(gdb) r   //(gdb)n  //(gdb) p a  //breakpoint f //c-continue
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&data);
//addAtBegg(&head,data);
addAtLast(&head,data);
}
//scanf("%d",&pos);
//scanf("%d",&data);
addAtPos(&head,data,pos);
//deleteAtPos(&head,data,pos);

//reverse(&head,data);

/*int c=search(&head,data);

if(c==1)
{
searchanddelete(&head,data);
else
{
    printf("not present");
}*/



//deleteAtBegg(&head,data);
//deleteAtEnd(&head,data,n);
for(i=0;i<n;i++)
{
print(&head,data);
}
return 0;
}
