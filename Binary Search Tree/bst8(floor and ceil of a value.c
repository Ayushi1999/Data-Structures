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
struct node* findFloor(struct node* root,int key)
{
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    else if(key<root->data)
    {
       return findFloor(root->left,key);
    }
    else {
       struct node* floor=root;
       struct node* ans=findFloor(root->right,key);
       if(ans == NULL)
          return floor;
       else
        return ans;
    }
}
struct node* findCeil(struct node* root,int key)
{
    if(root == NULL)
        return NULL;
    else if(root->data==key)
        return root;
    else
    {
        if(key>root->data)
        {
            return findCeil(root->right,key);
        }
        struct node* ceil=root;
        struct node* ans=findCeil(root->left,key);
        if(ans==NULL)
        {
            return ceil;
        }
        else
        {
            return ans;
        }
    }
}
int main()
{
    int key;
    struct node* root=newnode(7);
    root->left=newnode(4);
    root->right=newnode(10);
    root->left->left=newnode(1);
    root->left->right=newnode(5);
    root->left->left->right=newnode(2);
    root->right->left=newnode(8);
    root->right->right=newnode(12);
    scanf("%d",&key);
    struct node* t=findFloor(root,key);
    struct node* t1=findCeil(root,key);
  //  printf("%d\n",t->data);
    printf("%d",t1->data);
    return 0;
}
