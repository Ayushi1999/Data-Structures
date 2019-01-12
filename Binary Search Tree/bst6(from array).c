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
/*int qsort(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}*/
/*void convertToBST(int a[],int low,int n)
{
    if(low>n)
        return NULL;
    mid=(low+(n))/2;
    struct node* root=newnode(a[mid]);
    root->left=convertToBST(a,low,mid-1);
    root->right=convertToBST(a,mid+1,n);
    return root;
}*/
struct node* converToBST(struct node* root,int item)
{
    struct node* nn;
    if(root==NULL)
    {
        nn=newnode(root->data);
        return nn;
    }
    else if(item<root->data)
    {
        nn->left=converToBST(root->left,item);
    }
    else if(item>root->data)
    {
        nn->right=convertToBST(root->right,item);
    }
    return root;
}
void preorder(struct node* root,int *k,int pre[])
{
    if(root == NULL)
        return;
    pre[(*k)++]=root->data;
    preorder(root->left,k,pre);
    preorder(root->right,k,pre);
}
int main()
{
    struct node* root=NULL;
    int t;
    int n,a[1000];
    int i,item;
    int temp[1000];
    scanf("%d",&t);
    while(t--)
    {
       // int temp[1000];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            temp[i]=a[i];
        }
      //  qsort(a,n,sizeof(int),comp);
      for(i=0;i<n;i++)
      {
        struct node* t=convertToBST(root,a[i]);
      }
      int k=0,int flag=1;
      int pre[10000];
      preorder(t,pre,&k);
      for(i=0;i<n;i++)
      {
          if(temp[i]!=pre[i])
          {
              flag=0;
          }
      }
      if(flag == 0)
        printf("not a valid bst");
      else
        printf("yes");
    }
}
