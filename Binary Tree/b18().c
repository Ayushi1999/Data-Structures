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
void fun(struct node* root,int len,int& maxlen,int sum,int& maxsum)
{
    if(root == NULL)
        {
            if(maxlen<len)
            {
                maxlen=len;
                maxsum=sum;
            }
            if(maxlen == len&&maxsum<sum)
            {
                maxsum=sum;
            }
            return;
        }
    fun(root->left,len+1,maxlen,sum+root->data,maxsum);
    fun(root->right,len+1,maxlen,sum+root->data,maxsum);
    //fun1(root,0,maxlen,0,maxsum);
}
int fun1(struct node* root)
{
      int maxlen=0;
    int maxsum=0;
       int len=0,sum=0;
    if(root==NULL)
    {
        return 0;
    }
    fun(root,len,maxlen,sum,maxsum);
    return maxsum;
}
int main()
{
    struct node* root=newnode(4);
    root->left=newnode(2);
    root->left->right=newnode(1);
    root->right=newnode(5);
    int c=fun1(root);
    printf("%d ",c);
}
