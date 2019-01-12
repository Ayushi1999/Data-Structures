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
struct node* FormTree(int in[],int post[],int low,int high,int *t)
{
    if(high<low)
        return NULL;
    else
    {
   // printf("Ddd");
  //  static int t=6;
    struct node* tt=(struct node*)malloc(sizeof(struct node));
    tt=newnode(post[(*t)--]);
    int i;
    for(i=low;i<=high;i++)
    {
        if(post[*t]==in[i])
        {
            //t--;
            break;
        }
    }
    //printf("fgfd");
    tt->right=FormTree(in,post,i+1,high,t);
    tt->left=FormTree(in,post,low,i-1,t);
    return tt;
    }
}
void printInorder(struct node* n)
{
    if(n==NULL)
        return;
    printInorder(n->left);
    printf("%d ",n->data);
    printInorder(n->right);
}
int main()
{
   int in[100]={4,2,5,1,6,3,7};
   int post[100]={4,5,2,6,7,3,1};
 //  printf("Fff");
 int t=6;
   struct node* nn=FormTree(in,post,0,6,&t);
   printInorder(nn);
    return 0;
}
