#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//stack<int>s;
typedef struct stack
{
int top;
char *arr;
}ss;
struct stack* createStack()
{
    struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
    s1->top=-1;
    s1->arr=(char*)malloc(sizeof(char)*1000);
    return s1;
};
int isFull(struct stack* mem)
{
    int x=5;
    if(mem->top==x)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void insert(struct stack* mem,int ele)
{
  /*  if(isFull(mem))
    {
        printf("values cannot be inserted");
    }
    else
    {   */
        (mem)->top=(mem)->top+1;
        (mem)->arr[(mem)->top]=ele;
       // printf("%c ",(mem)->arr[(mem)->top]);
   // }
}
void pop(struct stack* mem)
{
    (mem->top)--;
}
char peek(struct stack* mem)
{
    return mem->arr[mem->top];
}
int isEmpty(struct stack* mem)
{
    printf("%d",mem->top);
    if(mem->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void fun(struct stack *mem,char* str)
{
    int i;
    int flag=0;
    for(i=0;i<strlen(str);i++)
    {
      //   printf("hhhhh");   //{()}
        if(str[i]=='{'||str[i]=='['||str[i]=='(')
        {
        //    printf("hhhhh");
            insert(mem,str[i]);
        }
        if(str[i]=='}')
        {
            if(peek(mem)=='{')
                pop(mem);
            else
                flag=0;
                break;
        }
        if(str[i]==']')
        {
            if(peek(mem)=='[')
                pop(mem);
                else
                    flag=0;
                    break;
        }
        if(str[i]=='(')
        {
            if(peek(mem)==')')
                pop(mem);
                else
                    flag=0;
                    break;
        }
    }
    if(flag==0&&isEmpty(mem))
        printf("balanced");
    else
        printf("not");
   // print(mem);
}

void print(struct stack *mem)
{
   if(isEmpty(mem))
   {
       printf("pattern balanced");
   }
   else
   {
       printf("not");
   }
}
int main()
{
struct stack *stk=createStack();
int ele,ch;
int i;
char str[100];
gets(str);
fun(stk,str);
//print(stk);
}
