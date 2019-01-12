#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    char arr[100][100];
};
struct stack* createStack()
{
    struct stack* ss=(struct stack*)malloc(sizeof(struct stack));
    ss->top=-1;
 //   ss->arr=(char*)malloc(sizeof(char)*1000);
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
void push(struct stack *mem,char c[])
{
    mem->top=mem->top+1;
    strcpy((mem->arr[mem->top]),c);
  //  printf("%d",mem->arr[mem->top]);
}
/*void push1(struct stack *mem,char *c)
{
    mem->top=mem->top+1;
    mem->arr[mem->top]=c;
}*/
char pop(struct stack* mem,char c[])
{
    strcpy(c,mem->arr[mem->top--]);
}
void PreToInfix(struct stack* stk,char *str)   //*+AB-CD (Infix : (A+B) * (C-D) )
{
    int i,k=0;
    char x[100];
    char ss[100];
    char op[2];
    char p1[100];
    char p2[100];
    for(i=strlen(str)-1;i>=0;i--)
    {
        if(isOperand(str[i]))
        {
        //    printf("jj");
            op[0]=str[i];
            op[1]='\0';
            push(stk,op);
        }
        else
        {
            pop(stk,p1);
            pop(stk,p2);
            op[0]=str[i];
            strcpy(ss,"(");
            strcat(ss,p1);
            strcat(ss,op);
            strcat(ss,p2);
            strcat(ss,")");
            push(stk,ss);
       /*     //printf("%c",c);
            ss[k++]='(';
            ss[k++]=c;
            ss[k++]=str[i];
            ss[k++]=d;
            ss[k++]=')';
          //  printf("%s",ss);
            push1(stk,ss);
            //printf("("+c+str[i]+d+")");*/
        }
    }
    pop(stk,x);
//    ss[k]='\0';
    printf("%s",x);
}
int main()
{
    struct stack* stk=createStack();
    char str[1000];
    gets(str);
  //  printf("dd");
    PreToInfix(stk,str);
}
