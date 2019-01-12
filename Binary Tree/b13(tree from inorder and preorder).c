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
struct node* FormTree(int in[],int pre[],int low,int high)
{
    static int t=0;
    //printf("rfghj ");
    if(high<low)
        return NULL;
    else
    {
   // printf("Ddd");
  //  struct node* nn=newnode(pre[]);
    //static int t=0;t]
    struct node*tt=newnode(pre[t]);
    int i  = search(pre,in,low,high);
    (t)++;
    tt->left=FormTree(in,pre,low,i-1);
    tt->right=FormTree(in,pre,i+1,high);
    return tt;
    }
}
void printInorder(struct node* n)
{
    if(n == NULL)
        return;
    printInorder(n->left);
    printf("%d ",n->data);
    printInorder(n->right);
}
int main()
{
   int in[100]={4,2,5,1,6,3,7};
   int pre[100]={1,2,4,5,3,6,7};
 //  printf("Fff");
 // int index = 0;
   struct node* nn=FormTree(in,pre,0,6);
   printInorder(nn);
    return 0;
}
