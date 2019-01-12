#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
    char *t;
    *t=*a;
    *a=*b;
    *b=*t;
}
void reverse(char str[])
{
    int start=0,end=strlen(str)-1;
    while(start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}
int main()
{
int c=1234,i=0;
char *rem;
if(c==0)
{
    *(rem+i)='\0';
}
while(c!=0)
{
int y=c%10;
*(rem+i)=y+'0';
i++;
c=c/10;
}
if(c<0)
{
    *(rem+i)='-';
    i++;
}
*(rem+i+1)='\0';

reverse(rem);
printf("%s",rem);
return 0;
}
