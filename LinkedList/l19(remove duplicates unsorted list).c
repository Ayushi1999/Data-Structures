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
void duplicates(struct node** h)
{
    struct node* ptr1=*h;
    struct node* ptr2=*h;
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    while(ptr1!=NULL)
    {
       // printf("ccccccc");
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->data==ptr2->next->data)
            {
              temp=ptr2->next;
              ptr2->next=ptr2->next->next;
              free(temp);
            }
            else
            {
               // printf("vvvvvvv");
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
     //   printf("dfghjk");
    }
 //   printf("fghjk ");
    while((*h)!=NULL)
    {
        printf("%d ",(*h)->data);
        (*h)=(*h)->next;
    }
}
int main()
{
    struct node* head=NULL;
    int i,data;
    for(i=0;i<7;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    duplicates(&head);
    return 0;
}
