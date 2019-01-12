#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* isPanagram(char str[])
{
    int i;
    static char ss[4]="yes";
    int *str1=(int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++)
    {
        str1[i]=0;//the quick brown fox jumps over the lazy dog
    }
    int index=0;
    for(i=0;i<strlen(str);i++)
    {
        index=str[i]-'a';
        str1[index]=1;
    }
  //  str1[index]='\0';
    int flag=1;
    for(i=0;i<26;i++)
    {
        if(str1[i]==0)
        {
            strcpy(ss,"no");
            flag=0;
            break;
        }
    }
    return ss;
   // printf("%d",flag);
}
int main()
{
    char str[1000];
    gets(str);
    char *ss1=isPanagram(str);
    printf("%s",ss1);
    return 0;
}
