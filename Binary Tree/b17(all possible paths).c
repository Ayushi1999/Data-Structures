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
/*struct stack
{
    struct node* tt;
    struct stack* next;
};
void push(struct stack** ss,struct node* curr)
{
    struct stack* ss1=(struct stack*)malloc(sizeof(struct stack));
    ss1->tt=curr;
    ss1->next=(*ss);
    (*ss)=ss1;
}
struct node* pop(struct stack** top)
{
    struct node* nn1;
    struct stack* tp;
    tp=(*top);
    nn1=(tp)->tt;
    (*top)=(tp)->next;
    free(tp);
    return nn1;
}
int empty(struct stack* stk)
{
    if(stk == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/
void print(int a[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void PossiblePaths(struct node* root,int a[],int len)
{
    if(!root)
        return;
    a[len]=root->data;
    len++;
    if(root->left == NULL && root->right == NULL)
    {
        print(a,len);
    }
    PossiblePaths(root->left,a,len);
    PossiblePaths(root->right,a,len);
   /* struct stack* stk;
    if(root==NULL)
        return;
    push(&stk,root);
    PossiblePaths(root->left);
    if(root->right==NULL&&root->left==NULL)
    {
       while(!empty(stk))
        {
            struct node* t=pop(&stk);
            printf("%d ",t->data);
        }
    }
    else  {
    PossiblePaths(root->right);
    }
        struct node* curr=pop(&stk);*/
}
int main()
{
    struct node* root=newnode(1);
    root->left=newnode(2);  //1-2-3
    root->right=newnode(3);  //3-4-5
    root->left->left=newnode(4);  //4-5-6
    root->left->right=newnode(5); //3-
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    int *a=(int*)malloc(sizeof(int)*10000);
    int len=0;
    PossiblePaths(root,a,len);
  //  inorder(root);
}
