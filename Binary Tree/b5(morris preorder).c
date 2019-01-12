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
void MorrisPreorder(struct node* root)
{
    struct node* curr=root;
    struct node* pred;
    while(curr!=NULL)
    {
        if(!curr->left)
        {
            printf("%d ",curr->data);
            curr=curr->right;
        }
        else
        {
            pred=curr->left;
            while(pred->right!=NULL&&pred->right!=curr)
            {
                pred=pred->right;
            }
            if(pred->right==NULL)
            {
                printf("%d ",curr->data);
                pred->right=curr;
                curr=curr->left;
            }
            else
            {
                pred->right=NULL;
               // printf("%d ",curr->data);
                curr=curr->right;
            }
        }
    }
}
/*void postorder(struct node* x) {
    if(x == NULL)
        return;
    printf("%d ",x->data);
    postorder(x->left);
    postorder(x->right);
}*/
int main()
{
    struct node* root=newnode(10);
    root->right=newnode(30);
    root->right->right=newnode(40);
    root->left=newnode(5);
    root->left->left=newnode(-2);
    root->left->left->right=newnode(2);
    root->left->left->right->left=newnode(-1);
    root->left->right=newnode(6);
    root->left->right->right=newnode(8);
    MorrisPreorder(root);
  //  preorder(root);
    return 0;
}

