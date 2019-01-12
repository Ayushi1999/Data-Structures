#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Panagram(char str[][100],int str_count)
{
   // char* str1=(char*)malloc(sizeof(char)*26);
    char str1[100];
    int i=0,j=0;
    int k=0,index=0;
    int p=0;
    int t=0,l=0;
    for(i=0;i<26;i++)
    {
        *(str1+i)=0;
    }
 /*   for(i=0;i<26;i++)
    {
        printf("%d ",*(str1+i));
       // *(str1+i)=0;
    }  */
    i=0;
    while(i<str_count)
    {
        printf("%s ",str[i]);
        while(j<strlen(str[i]))
        {
            if(str[i][j]>='A'&&str[i][j]<='Z')
            {
                index=str[i][j]-'A';
                printf("\n%d ",index);
            }
            else if(str[i][j]>='a'&&str[i][j]<='z')
            {
                index=str[i][j]-'a';
                printf("\n%d ",index);
            }
            str1[k++]=index;
            j++;
        }
        for(p=0;p<strlen(str[i]);p++)
        {
            if(str[p]==0)
              l=0;
               break;
        }
        if(l==0)
        {
            str1[t++]=0;
        }
        else
        {
            str1[t++]=1;
        }
        printf("%s",str1);
        i++;
    }
   // return str1;
}
int main()
{
    char str[100][100];
   // int a[26];
    int x,str_count;
    int i;
    scanf("%d",&str_count);
    for(i=0;i<str_count;i++)
    {
    scanf("%s",str[i]);
    }
 //   int i;
    Panagram(str,str_count);
    //printf("%s",s);
    /*for(i=0;i<26;i++)
    {
        a[i]=0;
    }
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            x=str[i]-'A';
        }
        else if(str[i]>='a'&&str[i]<='z')
        {
            x=str[i]-'a';
        }
        a[x]=1;
    }
    int p=1;
    for(i=0;i<26;i++)
    {
        if(a[i]==0)
        {
            p=0;
            break;
        }
    }
    if(p==0)
    {
        printf("not a panagram");
    }
    else
    {
        printf("is a panagram");
    }*/
    return 0;
}
