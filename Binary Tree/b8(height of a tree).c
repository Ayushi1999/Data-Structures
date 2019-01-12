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
}
int height(struct node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        if(l>r)
        {
            return (l+1);
        }
        else
        {
            return (r+1);
        }
    }
}
int main()
{
struct node* root=newnode(1);
root->left=newnode(2);
root->left->left=newnode(4);
root->left->right=newnode(5);
root->left->right->left=newnode(6);
root->left->right->left->left=newnode(7);
root->right=newnode(3);
int c=height(root);
printf("%d ",c);
return 0;
}
