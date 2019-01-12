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
    struct node* nn=(struct node*)malloc(sizeof(struct node*));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
void Leftview(struct node* root,int level,int *max)
{
    if(root==NULL)
        return;
        if(*max<level)
        {
            printf("%d ",root->data);
            *max=level;
        }
        Leftview(root->left,level+1,max);
        Leftview(root->right,level+1,max);
}
void fun(struct node* root)
{
    int level=1;
    int max=0;
    Leftview(root,level,&max);
}
int main()
{
    struct node* root=newnode(4);
    root->left=newnode(5);
    root->right=newnode(2);
    root->right->left=newnode(3);
    root->right->right=newnode(1);
    root->right->left->left=newnode(6);
    root->right->left->right=newnode(7);
  //  fun(root);
    int level=1;
    int max=0;
    Leftview(root,level,&max);
    return 0;
}
