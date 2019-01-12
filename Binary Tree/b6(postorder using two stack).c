#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct stack
{
    struct node* tt;
    struct stack* next;
};
struct node* newnode(int data)
{
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
void push(struct stack** ss,struct node* n)
{
    struct stack* nn = (struct stack*)malloc(sizeof(struct stack));
    nn->tt=n;
    nn->next=(*ss);
    (*ss)=nn;
}
struct node* pop(struct stack** stk)
{
    struct stack* t;
    struct node* nn1;
    t=(*stk);
    nn1=t->tt;
    (*stk)=t->next;
    free(t);
    return nn1;
};
int empty(struct stack* stk)
{
    if(stk==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct stack* createStack()
{
    struct stack* ss = (struct stack*)malloc(sizeof(struct stack));
    ss->tt = (struct node*)malloc(sizeof(struct node));
    ss->next = NULL;
    return ss;
};
void postOrder(struct node* root)
{
    struct stack* stk1 = NULL;
    struct stack* stk2 = NULL;
   //struct stack* stk1=(struct stack*)malloc(sizeof(struct stack));
   // struct stack* stk2=(struct stack*)malloc(sizeof(struct stack));
    struct node* c;
    push(&stk1,root);
    //printf("nnnjj");
    while(!empty(stk1))
    {
         c=pop(&stk1);
      //   printf("%d ",c->data);
   //     printf("nnnjj");
        push(&stk2,c);
        if(c->left)
        {
            push(&stk1,c->left);
        }
        if(c->right)
        {
            push(&stk1,c->right);
        }
    }
   // printf("gggg");
    while(!empty(stk2))
    {
        c=pop(&stk2);
        printf("%d ",c->data);
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
    postOrder(root);
}
