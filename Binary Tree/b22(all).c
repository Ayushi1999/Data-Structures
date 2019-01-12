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
    struct stack* next;
    struct node* tt;
};
void push(struct stack** nn,struct node* curr)
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->tt=curr;
    ss->next=(*nn);
    (*nn)=ss;
}
struct node* pop(struct stack** ss)
{
    struct stack* t;
    t=*ss;
    struct node* nn;
    nn=t->tt;
    (*ss)=t->next;
    free(t);
    return nn;
}
struct node* peek(struct stack* ss)
{
    return ss->tt;
}
int empty(struct stack* s1)
{
    if(s1==NULL)
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
    while(1)
    {
        if(curr!=NULL)
        {
            push(&stk,curr);
            curr=curr->left;
        }
        else
        {
            if(empty(stk))
                break;
            struct node* temp=pop(&stk);
            printf("%d ",temp->data);
            if(temp->right)
            {
                curr=temp->right;
            }
        }
    }
}
void preorder(struct node* root)
{
    struct node* curr=root;
    struct stack* stk=NULL;
    while(1)
    {
        if(curr!=NULL)
        {
            printf("%d ",curr->data);
            push(&stk,curr);
            curr=curr->left;
        }
        else
        {
            if(empty(stk))
                break;
            struct node* temp=pop(&stk);
            if(temp->right)
            {
                curr=temp->right;
            }
        }
    }
}
void postorder(struct node* root)
{
    struct node* curr=root;
    struct stack* stk1=NULL;
    while(!empty(stk1)||curr)
    {
        if(curr!=NULL)
        {
            push(&stk1,curr);
            curr=curr->left;
        }
        else
        {
            struct node* temp=peek(stk1)->right;
            if(temp == NULL)
            {
                temp=pop(&stk1);
                printf("%d ",temp->data);
                while(!empty(stk1) && temp==peek(stk1)->right)
                {
                    temp=pop(&stk1);
                    printf("%d ",temp->data);
                }
            }
            else
            {
                curr=temp;
            }
        }
    }
}
int height(struct node* root)
{
    if(root  == NULL)
        return;
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
        {
            return lheight+1;
        }
        else
        {
            return rheight+1;
        }
    }
}
int max(int a,int b)
{
    return a>b?a:b;
}
int diameter(struct node* root)
{
    if(root  == NULL)
        return;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        int c=l+r+1;
        int x=diameter(root->left);
        int y=diameter(root->right);
        return max(c,max(x,y));
    }
}
struct node* constructTree(int in[],int pre[],int low,int high)
{
    static int t=0;
    if(high<low)
    {
        return NULL;
    }
    else
    {
    struct node* nn=newnode(pre[(t)]);
    int i;
    for(i=low;i<high;i++)
    {
        if(pre[(t)]==in[i])
        {
            break;
        }
    }
    (t)++;
    nn->left=constructTree(in,pre,low,i-1);
    nn->right=constructTree(in,pre,i+1,high);
    return nn;
    }
}
struct node* constructTree1(int in[],int post[],int low,int high)
{
    static int t=6;
    if(high<low)
    {
        return NULL;
    }
    else
    {
    struct node* nn=newnode(post[(t)]);
    int i;
    for(i=low;i<high;i++)
    {
        if(post[(t)]==in[i])
        {
            break;
        }
    }
    (t)--;
    nn->right=constructTree(in,post,i+1,high);
    nn->left=constructTree(in,post,low,i-1);
    return nn;
    }
}
void MorrisInorder(struct node* root)
{
    struct node* curr=root;
    struct node* temp;
    while(curr!=NULL)
    {
        if(!curr->left)
        {
            printf("%d ",curr->data);
            curr=curr->right;
        }
        else
        {
            temp=curr->left;
            while(temp->right!=NULL&&temp->right!=curr)
            {
                temp=temp->right;
            }
            if(temp == NULL)
            {
             //   printf("%d ",curr->data);
                temp->right=curr;
                curr=curr->left;
            }
            else
            {
                temp->right=NULL;
                printf("%d ",curr->data);
                curr=curr->right;
            }
        }
    }
}
void MorrisPreorder(struct node* root)
{
    struct node* curr=root;
    struct node* temp;
    while(curr!=NULL)
    {
        if(!curr->left)
        {
            printf("%d ",curr->data);
            curr=curr->right;
        }
        else
        {
            temp=curr->left;
            while(temp->right!=NULL&&temp->right!=curr)
            {
                temp=temp->right;
            }
            if(temp == NULL)
            {
                printf("%d ",curr->data);
                temp->right=curr;
                curr=curr->left;
            }
            else
            {
                temp->right=NULL;
               // printf("%d ",curr->data);
                curr=curr->right;
            }
        }
    }
}
int main()
{
    int in[]={4,2,5,1,6,3,7};
    int pre[]={1,2,4,5,3,6,7};
    int post[]={4,5,2,6,7,3,1};
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    int x=height(root);
    printf("%d ",x);
     printf("\n");
    int y=diameter(root);
    printf("%d ",y);
     printf("\n");
    int t=0;
    struct node* nn1=constructTree(in,pre,0,7);
    inorder(nn1);
    printf("\n");
    struct node* nn2=constructTree1(in,post,0,7);
    inorder(nn1);
    printf("\n");
    MorrisInorder(root);
    printf("\n");
    MorrisPreorder(root);
}
