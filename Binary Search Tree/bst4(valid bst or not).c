#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int d)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=d;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
int checkBST(struct node* root,int min,int max)
{
    if(root == NULL)
    {
        return 1;
    }
    if(root->data<=min||root->data>=max)
    {
            return 0;
    }
   // return checkBST(root->left,min,root->data)&&checkBST(root->right,root->data,max);
    int x=checkBST(root->left,min,root->data);
    if(x)
    {
        return checkBST(root->right,root->data,max);
    }
}
int main()
{
    struct node* root=newnode(4);
    root->left=newnode(2);
    root->right=newnode(5);
    root->left->left= newnode(1);
    root->left->right=newnode(3);
    //root->right->left=newnode(5);
   // root->right->right=newnode(10);
   // root->right->right->right=newnode(12);
    int min=0,max=10000;
    int x=checkBST(root,min,max);
    printf("%d ",x);
    return 0;
}
