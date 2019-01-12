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
int height(struct node* r)
{
    if(r == NULL)
        return 0;
    else
    {
        int l1=height(r->left);
        int r1=height(r->right);
        if(l1>r1)
        {
            return l1+1;
        }
        else
        {
            return r1+1;
        }
    }
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int diameter(struct node* root)
{
    if(root == NULL)
        return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        int c=l+r+1;//path that passes through root.

        int t1=diameter(root->left);
        int t2=diameter(root->right);
        int d=max(t1,t2);
        return max(c,d);
       // printf("%d ",max(c,d));
    }
}
int main()
{
struct node* root=newnode(1);
root->left=newnode(2);
root->left->left=newnode(8);
root->left->left->right=newnode(9);
root->left->left->right->left=newnode(10);
root->left->left->left=newnode(7);
root->left->right=newnode(9);
root->left->right->right=newnode(5);
root->left->right->right->right=newnode(6);
root->left->right->right->right->right=newnode(6);
root->right=newnode(7);
int x=diameter(root);
printf("%d",x);
return 0;
}
