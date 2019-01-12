#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int *arr;
};
struct stack* createStack()
{
    struct stack* ss1=(struct stack*)malloc(sizeof(struct stack));
    ss1->arr=(int*)malloc(sizeof(int)*1000);
    ss1->top = -1;
    return ss1;
}
void push(struct stack* ss,char c)
{
    ss->top=ss->top+1;
    ss->arr[ss->top]=c;
}
int pop(struct stack* ss)
{
    int x=ss->arr[ss->top];
    ss->top--;
    return x;
}
void fun(char ch[])
{
    int i;
    struct stack* stk=createStack();
    for(i=0;ch[i]!='\0';i++)
    {
        if(isdigit(ch[i]))  //inbuilt method.
        {
            push(stk,ch[i]-'0');
        }
        else
        {
            int c=pop(stk);
            int d=pop(stk);
            switch(ch[i])
            {
            case '+':
                push(stk,c+d);
                break;
            case '-':
                push(stk,d-c);
                break;
            case '*':
                push(stk,c*d);
                break;
            case '/':
                push(stk,d/c);
                break;
            }
        }
    }
    printf("%d ",pop(stk));
}
int main()
{
    char ch[]="231*+9-";
    fun(ch);
}
