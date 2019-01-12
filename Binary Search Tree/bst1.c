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
struct node* insert(int item,struct node* root)
{
    struct node* n1;
    if(root==NULL)
    {
        n1=newnode(item);
        return n1;
    }
    else if(item>root->data)
    {
        root->right=insert(item,root->right);
    }
    else
    {
        root->left=insert(item,root->left);
    }
    return root;
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
    struct node* t;
    int item,i;
    struct node* root=NULL;
    for(i=0;i<5;i++)
    {
    scanf("%d",&item);
    root=insert(item,root);
    }
   // insert(7,root);
   // insert(2,root);
   // insert(9,root);
   // insert(3,root);
    inorder(root);
    return 0;
}
