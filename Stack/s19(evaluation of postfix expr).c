#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *arr;
    int top;
};
struct stack* createStack()
{
    struct stack* ss = (struct stack*)malloc(sizeof(struct stack));
    ss->top = -1;
    ss->arr = (int*)malloc(sizeof(int)*10000);
    return ss;
};
void push(struct stack* ss,int c)
{
    (ss)->top = (ss)->top+1;
    (ss)->arr[(ss)->top] = c;
}
void pop(struct stack* ss)
{
    ss->top--;
}
int peek(struct stack* ss)
{
    return ss->arr[ss->top];
}
int main()
{
    struct stack* stk = createStack();
    char ch[100];
    int i;
    scanf("%[^\n]s",ch);
    for(i=0;ch[i]!='\0';i++)
    {
        int num = 0;
       // printf("Dddd");
        if(ch[i] == ' ')
        {
            continue;
        }
        else
        {
            if(ch[i]>='0' && ch[i]<='9')
            {
                while(ch[i]!=' ')
                {
                    num = num*10+ch[i]-'0';   //2 3 11 * + 9 -;
                    i++;
                }
                push(stk,num);
            }
            else
            {
                int x = peek(stk);
                pop(stk);
                int y = peek(stk);
                pop(stk);
                switch(ch[i])
                {
                case '+':
                    push(stk,x+y);
                    break;
                case '-':
                    push(stk,y-x);
                    break;
                case '*':
                    push(stk,x*y);
                    break;
                case '/':
                    push(stk,y/x);
                    break;
                }
            }
        }
    }
    printf("%d",peek(stk));
    return 0;
}
