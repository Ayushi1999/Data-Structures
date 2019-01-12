#include<stdio.h>
int my_strcmp(char* a,char* b)
{
    return (*a==*b&&*b=='\0')?0:(*a==*b)?my_strcmp(++a,++b):1;
}
int main()
{
char* str="geeksjjjj   kk";
char* str1="geeks";
int d=my_strcmp(str,str1);
printf("%d",d);
}
