#include<stdio.h>
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
void insert(struct node** root,int data)
{
    queue<struct node*>q;
  //  q.push(root);
    if(root == NULL)
    {
        root=newnode(data);
    }
    else
    {
    q.push(root);
    while(!q.empty())
    {
        struct node* t=q.front();
        q.pop();
        if(t->left)
        {
            q.push(t->left);
        }
        else
        {
            t->left=newnode(data);
            break;
        }
        if(t->right)
        {
            q.push(t->right);
        }
        else
        {
            t->right=newnode(data);
            break;
        }
    }
    }
}
int main()
{
    struct node* root=NULL;
    for(i=1;i<6;i++)
    {
    insert(&root,i);
    }
}
