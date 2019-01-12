#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    char arr[100][100];
    int top;
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
    return ss;
}
void push(struct stack* ss,char c[])
{
    ss->top=ss->top+1;
    strcpy(ss->arr[ss->top],c);
}
char pop(struct stack* ss,char c[])
{
    strcpy(c,ss->arr[ss->top--]);
}
int isOperand(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void PreToPostfix(char ch[])
{
    struct stack* stk=createStack();
    int i;
    char op[2];
    char p1[100];
    char p2[100];
    char temp[1000];
    for(i=strlen(ch)-1;i>=0;i--)
    {
        if(isOperand(ch[i]))
        {
            op[0]=ch[i];
            op[1]='\0';
            push(stk,op);
        }
        else
        {
            pop(stk,p1);
            pop(stk,p2);
            op[0]=ch[i];
            strcpy(p1);
            strcat(p2);
            strcat(op);
            push(stk,temp);
        }
    }
    printf("%s",temp);
}
int main()
{
    char str[1000];
    gets(str);
  //  printf("dd");
    PreToPostfix(str);
}
