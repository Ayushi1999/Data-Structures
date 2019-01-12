#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct queue
{
    struct node* *arr;
    int front;
    int back;
};
struct queue* createQueue()
{
    struct queue* qq=(struct queue*)malloc(sizeof(struct queue));
    qq->arr=(struct node**)malloc(sizeof(struct node*)*10000);
    qq->front=-1;
    qq->back=-1;
    return qq;
}
struct node* newNode(int data)
{
    struct node* nn=(struct node*)malloc(sizeof(struct  node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
};
void enqueue(struct queue* q1,int x)
{
    q1->back=q1->back+1;
    q1->arr[q1->back]=x;
}
struct node* dequeue(struct queue* q1)
{
    return q1->arr[q1->front++];
}
void LevelOrder(struct node* root)
{
    struct queue* qq=createQueue();
    struct node* temp=root;
    while(temp)
    {
        enqueue(qq,temp->data);
        struct node* x=dequeue(qq);
        if(x->left)
        {
            enqueue(qq,x->left->data);
        }
        if(x->right)
        {
            enqueue(qq,x->right->data);
        }
    }
}

int main()
{
      struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    LevelOrder(root);
}
