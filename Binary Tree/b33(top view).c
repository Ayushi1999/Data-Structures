#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int val;
    struct node* left;
    struct node* right;
}node;
struct queue
{
    node* arr[50];
    int front;
    int back;
};
void initialise1(struct queue* q2)
{
    //struct queue* q2=(struct queue*)malloc(sizeof(struct queue));
    //q2->arr=(node**)malloc(sizeof(node*));
    int i;
    for(i=0;i<50;i++)
    {
        q2->arr[i] = NULL;
        q2->front=-1;
        q2->back=-1;
    }
    //return q2;
}
void push1(struct queue* qq,node* curr)
{
    if((qq)->front==-1)
        (qq)->front++;
    (qq)->back++;
    (qq)->arr[(qq)->back]=curr;
}
void pop1(struct queue* q1)
{
    q1->front++;
}
node* front1(struct queue* q1)
{
    return q1->arr[q1->front];
}
int empty1(struct queue* q1)
{
    if((q1->front-q1->back)+1==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void TopView(struct node* root)
{
  //  printf("Ddd");
    struct queue* qq = (struct queue*)malloc(sizeof(struct queue));
    initialise1(qq);
    int a[100] = {0};
    int index,i;
    a[50]=root->data;
    push1(qq,root);
    while(!empty1(qq))
    {
       node* temp = front1(qq);
       pop1(qq);
       if(temp->left!=NULL)
       {
           i = temp->val;
           if(a[50-(i-1)]==0)
           {
               a[50-(i-1)] = temp->left->data;
           }
           push1(qq,temp->left);
       }
       if(temp->right!=NULL)
       {
           i = temp->val;
           if(a[50-(i+1)]==0)
           {
           a[50-(i+1)]=temp->right->data;
           }
           push1(qq,temp->right);
       }
    }
   // int i;
    for(i=100-1;i>=0;i--)
    {
        if(a[i]!=0)
        {
            printf("%d ",a[i]);
        }
    }
}
node* createBinary(node* root, int d, int v)
{
    if( root == NULL)
    {
        node* nn = (node*)malloc(sizeof(node));
        nn->data = d;
        nn->val = v;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    else if(d < root->data)
    {
        root->left = createBinary(root->left, d, v-1);
    }
    else
    {
        root->right = createBinary(root->right,d, v+1);
    }
    return root;
}

int main()
{
    int n,no;
    node* root=NULL;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&no);
        root = createBinary(root,no,0);
      //  printf("ddd");
    }
    TopView(root);
    //complete this function
    return 0;
}
