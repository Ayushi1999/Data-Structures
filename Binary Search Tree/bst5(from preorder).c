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
struct node* fun(int a[],int *low,int high,int min,int max)
{
    struct node* nn=NULL;
    if(a[*low]<=min||a[*low]>=max)
    {
        return 0;
    }
    else
    {
    if(*low<=high)
    {
         nn=newnode(a[*low]);
        *low=*low+1;
        nn->left=fun(a,low,high,min,nn->data);
        nn->right=fun(a,low,high,nn->data,max);
    }
    }
    return nn;
}
void inorder(struct node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
int main()
{
    struct node* root=NULL;
    int a[1000]={10, 5, 1, 7, 40, 50};
    int low=0;
    int high=5;
    int min=0,max=10000;
    int index=0;
    struct node* t=fun(a,&low,high,min,max);
    inorder(t);
    return 0;
}
