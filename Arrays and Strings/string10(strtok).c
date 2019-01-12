#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

void strokh(char * A)
{
    int i=0;
    int x = strlen(A);
    while(A[i] != '\0')
    {
        if(A[i] == ' ')
        {
            A[i] = '\n';
        }
        i++;
    }
}

int main()
{
    char A[] = "Anchit is awesome";
    strokh(A);
    puts(A);
}
