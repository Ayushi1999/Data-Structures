//left root right
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
struct stack
{
    struct node* tt;
    struct stack* next;
};
void push(struct stack** top,struct node* curr)
{
    struct stack* ss1=(struct stack*)malloc(sizeof(struct stack));
    ss1->tt=curr;
    ss1->next=(*top);
    (*top)=ss1;
}
struct node* pop(struct stack** top)
{
    struct node* nn1;
    struct stack* tp;
    tp=*top;
    nn1=(tp)->tt;
    (*top)=(tp)->next;
    free(tp);
    return nn1;
}
int isEmpty(struct stack* ss)
{
    if(ss==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void inorder(struct node* root)
{
    struct node* curr=root;
    struct stack* stk=NULL;
    int t=1;
    while(t)
    {
        if(curr!=NULL)
        {
            push(&stk,curr);
            curr=curr->left;
        }
        else
        {
            if(isEmpty(stk))
            {
                t=0;
            }
            else
            {
          //  struct node* nn=peek(&stk);
            curr=pop(&stk);
            printf("%d ",curr->data);
            curr=curr->right;
            }
        }
    }
}
int main()
{
/*     struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);*/
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    inorder(root);
}
