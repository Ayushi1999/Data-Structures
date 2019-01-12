#include<stdio.h>
using namespace std;
struct node
{
int data;
struct node* left;
struct node* right;
};
struct node* newnode(int data)
{
    struct node* temp=new node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
};
void insert(struct node* root,int i)
{
    queue<struct node*>q;
    q.push(temp);
    while(!q.empty())
    {
        struct node *temp=q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left=newnode(data);
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if(!temp->right)
        {
            temp->left=newnode(data);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    struct tree* t=(struct tree*)malloc(sizeof(struct tree*));
    struct node* root=newnode(0);
    for(i=1;i<n;i++)
    {
        insert(root,i);
    }
    //printf("sss");
}
