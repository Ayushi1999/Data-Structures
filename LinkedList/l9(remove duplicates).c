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
       while(curr->next!=NULL)
       {
           curr=curr->next;
       }
       curr->next=nn;
    }
}
void duplicates(struct node* h)
{
    struct node* ptr1=h;
    struct node* ptr2;
 //   struct node* ptr3=(struct node*)malloc(sizeof(struct node*));
    struct node* temp;
    while(ptr1!=NULL&&ptr1->next!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
           // ptr3=ptr2;
            if(ptr1->data==ptr2->next->data)
            {
                temp=ptr2->next->next;
                free(ptr2->next);
                ptr2->next=temp;  //just pointing the address.
             /*temp=ptr2->next;
             ptr2->next=ptr2->next->next;
             free(temp);*/
             //ptr2=temp;
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }


    //struct node* curr=*h;
    //struct node* nn1;

  /*  while(curr&&curr->next)
    {
    if(curr->data==(curr->next)->data)
    {
        nn1=curr->next->next;
        free(curr->next);
        curr->next=nn1;
    }
    else
    {
        curr=curr->next;
    }
    }*/
    while(h!=NULL)
    {
        printf("%d ",(h)->data);
        h=(h)->next;
    }
}
int main()
{
    struct node* head=NULL;
    int i,data;
    for(i=0;i<8;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    duplicates(head);
    return 0;
}
