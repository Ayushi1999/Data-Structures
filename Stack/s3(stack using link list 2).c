#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createNode()
{
    struct node* nn=(struct node*)malloc(sizeof(struct node*));
    return nn;
};
void insertAtBegg(struct node **stk,int d)
{
    struct node* nn1=createNode();
    if(nn1 == NULL)
        return;
    else
        nn1->data=d;
        nn1->next=(*stk);
        *stk=nn1;
        printf("%d",nn1->data);
}
void deleteAtBegg(struct node **stk,int d)
{
    if(*stk == NULL)
    {
        return -1;
    }
    else
    {
        struct stack* nnnn=*stk;
        (*stk) =(*stk)->next;
       // int temp=nnnn->data;
        free(temp);
    }
}
int main()
{
    struct node *stk=NULL;
    int data;
    scanf("%d",&data);
    insertAtBegg(&stk,data);
    deleteAtBegg(&stk,data);
    return 0;
}
