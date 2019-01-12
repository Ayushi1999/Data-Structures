#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    char *arr;
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
    ss->arr=(char*)malloc(sizeof(char)*1000);
    return ss;
}
int isOperand(char ch)
{
    if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *mem,char c)
{
    mem->top=mem->top+1;
    mem->arr[mem->top]=c;
}
char pop(struct stack* mem)
{
   return mem->arr[mem->top--];
}
int isEmpty(struct stack *mem)
{
    if(mem->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char peek(struct stack* mem)
{
    return mem->arr[mem->top];
}
int Prec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
int InToPost(struct stack *stk,char ch[])
{
    int i,k=0;
  /* if(!stk)
        return -1;  */

    for(i=0;i<strlen(ch);i++)
    {
        if(isOperand(ch[i]))
        {
           ch[k++]=ch[i];
        }
        else if(ch[i]=='(')
        {
            push(stk,ch[i]);
        }
        else if(ch[i]==')')
        {
            while(!isEmpty(stk) && peek(stk)!='(')
            {
                char x=pop(stk);
                ch[k++]=x;
            }
            if(peek(stk)=='(')
                pop(stk);
           /*  if (!isEmpty(stk) && peek(stk) != '(')
                return -1; // invalid expression
            else
                pop(stk);*/
        }
        else
        {
            while(!isEmpty(stk)&&Prec(ch[i])<=Prec(peek(stk)))
            {
                ch[k++]=pop(stk);
            }
            push(stk,ch[i]);
        }
    }
    while(!isEmpty(stk))
    {
        ch[k++]=pop(stk);
    }
    ch[k]='\0';
    printf("%s",ch);
}
int main()
{
    struct stack* stk=createStack();
    char ch[]="(a+b)*(c+d)";
    InToPost(stk,ch);
}
