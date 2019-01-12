#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}
int uniqueCharacters(char str[])
{
    int i,j;
    int c=1;
    qsort(str,strlen(str),sizeof(char),comp);
    for(i=0;i<strlen(str);i++)
    {
            if(str[i]==str[i+1])
            {
                c=0;
                break;
            }

    }
    return c;
}
int main()
{
  char str[1000] = "abcde";

    if(uniqueCharacters(str)) {
        printf("The String has all unique characters\n");
    }
    else {
        printf("not");
    }
	//code
	return 0;
}
