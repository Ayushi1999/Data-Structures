#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    char str1[1000];
    gets(str);
    gets(str1);
    int i;
    void *p;
    int len=strlen(str);
    char *str2=(char*)malloc(sizeof(char)*(len*2));
        strcat(str2,str);
        strcat(str2,str);
        p=strstr(str2,str1);
    if(p==NULL)
    {
        printf("no rotations");
    }
    else
    {
        printf("yes");
    }


}
