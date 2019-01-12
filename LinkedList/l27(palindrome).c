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
void reverse(struct node** h)
{
    struct node* prev=NULL;
    struct node* curr3=*h;
    struct node* temp;
    while(curr3!=NULL)
    {
        temp=curr3->next;
        curr3->next=prev;
        prev=curr3;
        curr3=temp;
    }
    *h=prev;
}
int compareLists(struct node* h,struct node* h1)
{
    struct node* p1=h;
    struct node* p2=h1;
    int flag=0;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data==p2->data)
        {
        p1=p1->next;
        p2=p2->next;
        flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}
void Palindrome(struct node* h1,int n)
{
    struct node* curr1=h1;
    struct node* curr2=h1;
    struct node* ptr;
    struct node* second_half;
 //   struct node* prev_curr1;
    struct node* midnode;
    if(h1!=NULL)
    {
        while((curr1!=NULL)&&(curr2->next!=NULL))
        {
            curr1=curr1->next;
            ptr=curr1;
            curr2=curr2->next->next;
        }
    }
    if(curr2!=NULL)
    {
        midnode=curr1;
        curr1=curr1->next;
    }
    second_half=curr1;
  //  prev_curr1=NULL;
    reverse(&second_half);
    int c = compareLists(h1,second_half);
    if(c==1)
    {
        printf("palindrome");
    }
    else
    {
        printf("not");
    }
}
    /*struct node* prev=NULL;
    struct node* curr=h1;
    struct node* curr2=h1;
    struct node* temp=NULL;*/

   /* while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    h1=prev;
    int flag=0;
    while(h1&&curr2)
    {
        if(h1->data==curr2->data)
        {
            flag=1;
            h1=h1->next;
            curr2=curr2->next;
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        printf("palindrome");
    }
    else
    {
        printf("not");
    }*/
   /* while(h1!=NULL)
    {
        printf("%d",h1->data);
        h1=h1->next;
    } */
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
    Palindrome(head,n);
    return 0;
}

