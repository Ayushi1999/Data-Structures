//root left right
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
void push(struct stack** st,struct node* curr)
{
    struct stack* nn=(struct stack*)malloc(sizeof(struct stack));
    nn->tt=curr;
    nn->next=(*st);
    (*st)=nn;
   // return nn;
}
struct node* pop(struct stack** stk)
{
    struct stack* t;
    struct node* nn1;
    t=*stk;
    nn1=t->tt;
    (*stk)=t->next;
    free(t);
    return nn1;
};
int isEmpty(struct stack* stk)
{
    if(stk == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void preorder(struct node* root)
{
    struct node* curr=root;
    struct stack* stk=NULL;
    int t=1;
    while(t)
    {
        if(curr!=NULL)
        {
            printf("%d ",curr->data);
            push(&stk,curr);
            curr=curr->left;
        }
        else
        {
            if(!isEmpty(stk))
            {
            curr=pop(&stk);
            curr=curr->right;
            }
            else
            {
                t=0;
            }
        }
    }
}
int main()
{
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    preorder(root);
}
