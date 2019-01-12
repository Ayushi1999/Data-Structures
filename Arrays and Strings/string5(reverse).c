#include<stdio.h>
void reverse(char str[],int count)
{
int i=0,word=0;
int t=0;
//int j=count-1;
int j;
char temp;
for(i=0;i<count;i++)
{
    if(str[i]==' '||str[i]=='\n'||str[i]=='\t')
    {
        t=0;
    }
    else if(t==0)
    {
        t=1;
        word++;
    }
    str1[k]=str[i];
    k++;
}

/*for(i=0;i<count;i++)
{
    if(str[i]==' ')
    {
        word++;
    }
}*/
printf("%d",word);

/*while(j<count)
{
 //   count=0;
    i=j;
while(str[i]!=' ')
{
   // count++;
    i++;
   // str1[j]=str[i];
}
j=i+1;
word++;
}*/
//printf("%d",word);
/*while(i<count/2)
{
    temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;
    j--;
}*/
}
int main()
{
char str[]="geeks for geeks kk ll";
int i,count=0;
i=0;
while(str[i]!='\0')
{
    count++;
    i++;
}
reverse(str,count);
/*for(i=0;i<count;i++)
{
    printf("%c",str[i]);
}*/
return 0;
}
