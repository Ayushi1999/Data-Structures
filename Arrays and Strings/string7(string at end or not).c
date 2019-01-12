#include<stdio.h>
int main()
{
    char str[100];
    char str1[100];
    gets(str);
    gets(str1);
    int len=strlen(str);
    int len1=strlen(str1);
    int i;
    int j=0;
    if(len>len1)
    {
    for(i=len-len1;i<len;i++)
    {
        if(str[i]!=str1[j])
        {
            printf("0") ;
            break;
        }
        j++;
    }
    printf("1");
    }
    return 0;
}
