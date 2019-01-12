#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createNode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
};
void addAtLast(struct node** h,int data)
{
    struct node* nn=createNode();
    if((*h)==NULL)
    {
        nn->data=data;
        nn->next=NULL;
        (*h)=nn;
    }
    else
    {
       nn->data=data;
       nn->next=NULL;
        struct node* curr=*h;
       while(curr->next!=NULL)
       {
           curr=curr->next;
       }
       curr->next=nn;
    }
}
void sort(struct node** h1)
{
	int temp;
	struct node *j,*i;
	for(j=(*h1);j!=NULL;j=j->next)
    {
		for(i=j;i!=NULL;i=i->next)
		{
			if(i->data < j->data)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
    }
}
struct node* MergeLists(struct node* h1,struct node* h2)
{
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    struct node* result = NULL;
    if(h1->data<h2->data)
    {
        result = h1;
        result->next = MergeLists(h1->next,h2);
    }
    else
    {
        result = h2;
        result->next = MergeLists(h1,h2->next);
    }
    return result;
}






/*struct node* MergeLists(struct node* h1,struct node* h2)
{
   // sort(&h1);
   // sort(&h2);
    struct node* result;
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    if(h1->data<=h2->data)
    {
        result=h1;
        result->next=MergeLists(h1->next,h2);
    }
    else
    {
        result=h1;
        result->next=MergeLists(h2->next,h1);
    }
  //  sort(&result);
    return result;
    /*
    //struct node* curr=NULL;
    struct node* ptr1=h1;
    struct node* ptr2=h2;
    struct node* curr=(struct node*)malloc(sizeof(struct node*));
    if(ptr1->data>ptr2->data)
    {
        curr->data=ptr2->data;
        curr=curr->next;
        ptr2=ptr2->next;
    }
    else
    {
       curr->data=ptr1->data;
       curr=curr->next;
        ptr1=ptr1->next;
    }
    while(ptr1&&ptr2)
    {
    if(ptr1->data<ptr2->data)
    {
        curr=(struct node*)malloc(sizeof(struct node*));
        curr->next=ptr1;
       //addAtLast(newnode,ptr1->data);
       ptr1=ptr1->next;
       curr=curr->next;
    }
    else if(ptr1->data>ptr2->data)
    {
        curr=(struct node*)malloc(sizeof(struct node*));
        curr->next=ptr2;
        //addAtLast(newnode,ptr2->data);
       ptr2=ptr2->next;
       curr=curr->next;
    }
   /* else
    {
        curr->next=ptr1;
        //curr=curr->next;
        curr->next=ptr2;
        //curr=curr->next;
        //addAtLast(newnode,ptr1->data);
        //addAtLast(newnode,ptr2->data);
       ptr1=ptr1->next;
       ptr2=ptr2->next;
    }*/
    //}
   /* while(ptr2!=NULL)
    {
        curr=(struct node*)malloc(sizeof(struct node*));
         curr->next=ptr2;
        curr=curr->next;
        // addAtLast(newnode,ptr2->data);
         ptr2=ptr2->next;
    }
    //curr=NULL;
    while(ptr1!=NULL)
    {
        curr=(struct node*)malloc(sizeof(struct node*));
         curr->next=ptr1;
        curr=curr->next;
        // addAtLast(newnode,ptr1->data);
         ptr1=ptr1->next;
    }
   // curr=NULL;
    while(curr)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }*/
   // reverseprint(newnode);
//}
void reverseprint(struct node* nn)
{
    struct node* curr=nn;
    if(nn==NULL)
    {
        return ;
    }
    else
    {
        reverseprint(curr->next);
        printf("%d ",curr->data);
    }
}
/*void print(struct node* newnode)
{
    while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
}*/
int main()
{
    struct node* head=NULL;
    struct node* head1=NULL;
    struct node* newnode=NULL;
    int data,i;
    for(i=0;i<3;i++)
    {
        scanf("%d",&data);
        addAtLast(&head,data);
    }
    for(i=0;i<3;i++)
    {
        scanf("%d",&data);
        addAtLast(&head1,data);
    }
   // head->next->next->next->next->next=head;
    //detectLoop(head);
    struct node* j=MergeLists(head,head1);
    while(j!=NULL)
    {
        printf("%d ",j->data);
        j=j->next;
    }
   // print(newnode);
}


