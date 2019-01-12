#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
};
int Identical(struct node* A,struct node* B)
{
    if(A&&B)
    {
        if(A->data!=B->data)
        {
            return 0;
        }
        else
        {
        return Identical(A->left,B->left)&&Identical(A->right,B->right);
        }
    }
    else if(A==NULL&&B==NULL)
        return 1;
    else
        return 0;

}
int main()
{
  //  struct node* A=NULL;
   // struct node* B=newNode(1);
      struct node *A = newNode(1);
    A->left        = newNode(2);
    A->right       = newNode(3);
    A->left->left  = newNode(4);
    A->left->right = newNode(5);
    //LevelOrder(root);
       struct node *B = newNode(1);
    B->left        = newNode(2);
    B->right       = newNode(3);
    B->left->left  = newNode(4);
    B->left->right = newNode(5);
    //LevelOrder(root);*/
    int c=Identical(A,B);
    printf("%d ",c);
}
