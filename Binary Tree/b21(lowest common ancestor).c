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
struct node* LowestCommonAncestor(struct node* root,int x,int y)
{
    //printf("Xvbf");
    if(root == NULL)
        return NULL;
    if(root->data == x||root->data == y)
        return root;
    root->left=LowestCommonAncestor(root->left,x,y);
    root->right=LowestCommonAncestor(root->right,x,y);
    if(root->left==NULL)
    {
        return root->right;
    }
    else
    {
        return root->left;
    }

    //printf("tttt");
    if((root->left==NULL)&&(root->right==NULL))
    {
        return NULL;
    }
    if(root->left&&root->right)
    {
        return root;
    }
}
int main()
{
    int x,y;
    struct node *root =newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    scanf("%d %d",&x,&y);
    struct node* temp=LowestCommonAncestor(root,x,y);
    printf("%d ",temp->data);
    return 0;
}
