#include<stdio.h>
int main()
{
    char str[100];
    char patt[100];
    gets(str);
    gets(patt);
    int index,i,j;
    int len=strlen(str);  //geeks
    int len1=strlen(patt);   //hellogeeks
    for(i=0;i<len;i++)
    {
        for(j=0;j<len1;j++)
        {
            if(str[i+j]==patt[j])
            {
                index=i+j;
            }
            else
            {
                break;
                index=0;
            }
        }
    }
    printf("%d",index);
    return 0;
}
