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
void inorder(struct node* root,int *a,int *k)
{
     if(root == NULL)
         return;
     inorder(root->left,a,k);
     a[(*k)++]=root->data;
     inorder(root->right,a,k);
}
int kthsmallest(struct node* A, int B)
{
    int k=0,t=0;
    int *a=(int*)malloc(sizeof(int)*100000);
    inorder(A,a,&k);
    int i;
    for(i=1;i<=k;i++)
    {
        if(i==B)
        {
            t=a[i];
            break;
        }
    }
    return t;
}
/*void inorder(struct node* root,int a[],int *p)
{
    if(root == NULL)
        return;
    inorder(root->left,a,p);
    a[(*p)++]=root->data;
    inorder(root->right,a,p);
}
int fun(struct node* root,int k,int a[])
{
   // struct node* curr=root;
    int p=0,i;
    inorder(root,a,&p);
    for(i=0;i<p;i++)
    {
        if(i==p-k)
        {
            return a[i];
            //printf("%d ",a[i]);
        }
    }
}*/
int main()
{
    int k;
  //  int a[1000];
    struct node* root=newnode(7);
    root->left=newnode(4);
    root->right=newnode(10);
    root->left->left=newnode(1);
    root->left->right=newnode(5);
    root->left->left->right=newnode(2);
    root->right->left=newnode(8);
    root->right->right=newnode(12);
    scanf("%d",&k);
    int t=kthsmallest(root,k);
    //int t=fun(root,k,a);
    printf("%d",t);
    return 0;
}
