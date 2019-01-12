#include<stdio.h>
int comp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}
int main()
{
    char str[1000]="geeksforgeeks";
    int i=0;
    qsort(str,strlen(str),sizeof(char),comp);
    int j=0;
    int k=0;
    char str2[100];
    while(str[j]!='\0')
    {
        if(str[j]!=str[j-1])
        {
            str2[k]=str[j];
            k++;
        }
        j++;
    }
    str2[k]='\0';
    for(i=0;i<k;i++)
    {
        printf("%c",str2[i]);
    }
}
