#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int arr[100][100];
};
struct stack* createStack()
{
    struct stack* ss = (struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
   // ss->arr=(int*)malloc(sizeof(int)*1000);
    return ss;
}
void push(struct stack* ss,char c[])
{
    ss->top = ss->top+1;
    strcpy(ss->arr[ss->top],c);
}
char pop(struct stack* ss,char p1[])
{
    strcpy(p1,ss->arr[ss->top--]);
}
/*char peek(struct stack* ss)
{
    return ss->arr[ss->top];
}*/
int isOperand(char ch)
{
    if(ch>='A' && ch<='Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void fun(char ch[])
{
    int i;
    char op[2];
    char temp[100];
    char x[100],y[100];
    struct stack* stk = createStack();
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
          //  char c=peek(stk);
            pop(stk,x);
          //  char d=peek(stk);
            pop(stk,y);
            op[0]=ch[i];
            strcpy(temp,"(");
            strcat(temp,x);
            strcat(temp,op);
            strcat(temp,y);
            strcat(temp,")");
            push(stk,temp);
        }
    }
    printf("%s",temp
           );
}
int main()
{
    char ch[100] = "*+AB-CD";  //prefix to infix.
    fun(ch);
    return 0;
}
