#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

struct queue
{
    struct node* *arr;
    int front,back;
};

struct queue* createQueue()
{
    struct queue* qq = (struct queue*)malloc(sizeof(struct queue));
    qq->arr = (struct node**)malloc(sizeof(struct node*)*1000);
    qq->front = -1;
    qq->back = -1;
    return qq;
}

void push(struct queue* qq,struct node* curr)
{
    if(qq->front == -1 && qq->back == -1)
    {
        qq->front++;
    }
    qq->back++;
    qq->arr[qq->back] = curr;
}

struct node* pop(struct queue* q)
{
    struct node* temp = q->arr[q->front];
    if(q->front == q->back)
    {
        q->front = -1;
        q->back = -1;
    }
    else
    {
        q->front++;
    }
    return temp;
}

int empty(struct queue* qq)
{
    if(qq->front == -1 && qq->back == -1)
    {
        return 1;
    }
    return 0;
}

struct node* createBinary(struct node* root,int data)
{
    if(root == NULL)
        return newnode(data);
    else if(data<root->data)
    {
        root->left = createBinary(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = createBinary(root->right,data);
    }
    return root;
}
void fun(struct node* root)
{
    struct queue* qq = createQueue();
    push(qq,root);
    int sum = 0;
    int sum1 = 0;
    int count = 0,level = 1;
    int c = 1,i;
    while(!empty(qq))
    {
        for(i=0;i<c;i++)
        {
            struct node* temp = pop(qq);
            if(level%2!=0)
            {
                sum = sum+temp->data;
            }
            else
            {
                sum1 = sum1+temp->data;
            }
            if(temp->left)
            {
                push(qq,temp->left);
                count++;
            }
            if(temp->right)
            {
                push(qq,temp->right);
                count++;
            }
        }
   // level++;
    c = count;
    count = 0;
    level++;
    }
    printf("%d",sum-sum1);
}
int main()
{
//    int arr[] = {5,2,6,4,1,8,3,7,9};
    struct node* root = NULL;
    int no,i;
    for(i=0;i<9;i++)
    {
        scanf("%d",&no);
        root = createBinary(root,no);
    }
    fun(root);
    return 0;
}
