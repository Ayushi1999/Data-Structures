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
};
struct stack
{
    struct node* *arr;
    int top;
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->arr=(struct node**)malloc(sizeof(struct stack*));
    ss->top=-1;
    return ss;
};
void push(struct stack* ss,struct node* curr)
{
    ss->arr[++ss->top]=curr;
}
struct node* pop(struct stack* stk)
{
    return stk->arr[stk->top--];
}
struct node* peek(struct stack* stk)
{
    return stk->arr[stk->top];
}
int empty(struct stack* stk)
{
    if(stk->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node* constructTree(int a[],int size)
{
    struct stack* stk=createStack();
    struct node* temp;
    struct node* temp1;
    temp1=newnode(a[0]);
    push(stk,temp1);
    int i;
    for(i=1;i<size;i++)
    {
        //printf("Dddd");
        temp=NULL;
        while(!empty(stk)&&a[i]>peek(stk)->data)
        {
            temp=pop(stk);
        }
        if(temp == NULL)
        {
            peek(stk)->left=newnode(a[i]);
            push(stk,peek(stk)->left);
        }
        else
        {
           temp->right=newnode(a[i]);
           push(stk,temp->right);
        }
    }
    return temp1;
}
void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    int a[100]={10, 5, 1, 7, 40, 50};
    int size=6;
    struct node* root=constructTree(a,size);
    inorder(root);
    return 0;
}
