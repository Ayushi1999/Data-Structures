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
void MirrorImage(struct node* A)
{
    //printf("rtyui ");
    if(A == NULL)
        return;
    else
    {
        MirrorImage(A->left);
        MirrorImage(A->right);
        struct node* temp;
        temp=A->left;
        A->left=A->right;
        A->right=temp;
    }
   //return A;
}
void PrintInorder(struct node* A)
{
    if(A == NULL)
        return;
    PrintInorder(A->left);
    printf("%d ",A->data);
    PrintInorder(A->right);
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
    MirrorImage(A);
    PrintInorder(A);
}
