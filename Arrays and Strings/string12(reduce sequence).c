#include<stdio.h>
int main()
{
char str[1000];
char str1[1000];
char ch;
gets(str);
scanf("%c",&ch);
int i=0;
int k=0;
while(str[i]!='\0')
{
if(str[i]==ch)
{
str1[k++]=str[i];
i++;
while(str[i]==ch)
{
    i++;
}
}
else
{
 str1[k++]=str[i];
 i++;
}
}
for(i=0;i<k;i++)
{
printf("%c",str1[i]);
}
}
