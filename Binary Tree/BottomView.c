#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int hd;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data,int h)
{
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->hd = h;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct queue
{
    struct node* *arr;
    int front,back;
};
struct queue* createQueue() {
    struct queue* q  = (struct queue*)malloc(sizeof(struct queue));
q->arr = (struct node**)malloc(sizeof(struct node*)*100);
q->front = -1;
q->back = -1;
return q;
}

void push(struct queue* q, struct node* data) {
    if(q->front == -1) {
        q->front = 0;
    }
    (q->back)++;
    q->arr[q->back] = data;
}

struct node* pop(struct queue* q)
{
    struct node* temp = q->arr[q->front];
    if(q->front == -1) {
        return NULL;
    }
    q->front++;
    return temp;
}

int isEmpty(struct queue* q)
{
    if((q->back-q->front+1) == 0)
    {
        return 1;
    }
    return 0;
}

struct node* createBinary(struct node* root,int no,int h)
{
    if(root == NULL)
        return newNode(no,h);
    else if(no<root->data)
    {
        root->left = createBinary(root->left,no,h-1);
    }
    else if(no>root->data)
    {
        root->right = createBinary(root->right,no,h+1);
    }
    return root;
}
void BottomView(struct node* root)
{
    int i;
    int *ar = (int*)malloc(sizeof(int)*100);
    for(i=0;i<100;i++)
    {
        ar[i] = 0;
    }
    struct queue* qq = createQueue();
    push(qq,root);
    while(!isEmpty(qq))
    {
        struct node* temp = pop(qq);
        if(temp->left)
        {
            push(qq,temp->left);
        }
        if(temp->right)
        {
            push(qq,temp->right);
        }
        ar[temp->hd] = root->data;
    }
    for(i=0;i<100;i++)
    {
        if(ar[i]!=0)
        {
            printf("%d ",ar[i]);
        }
    }
}
int main()
{
    struct node* root = NULL;
    int n,no;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&no);
        root = createBinary(root,no,0);
    }
    BottomView(root);
}
