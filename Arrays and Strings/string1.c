#include<stdio.h>
int main()
{
    char str[1000];
    char str1[1000];
    int i,j,p=0;
    gets(str);
    gets(str1);
    for(i=0,j=0;i<strlen(str),j<strlen(str1);i++,j++)
    {
        if(str[i]==str1[j])
        {
            p=0;
        }
        else if(str[i]<str1[j])
        {
            p=-1;
            break;
        }
        else
        {
            p=1;
            break;
        }
    }
    if(p==0)
    {
        printf("strings are equal");
    }
    else
    {
        printf("not");
    }
    for(i=0,j=strlen(str);i<strlen(str1);i++)
    {
        str[j++]=str1[i];
    }
    str[j]='\0';
    printf("%s",str);
}
