#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}
int main()
{
    int t,p=0,i,j;
    char ch[1000];
    char ch1[1000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",ch);
        scanf("%s",ch1);
        qsort(ch,strlen(ch),sizeof(char),comp);
        qsort(ch1,strlen(ch1),sizeof(char),comp);
       /* for(i=0;i<strlen(ch);i++){
            printf("%c %c ",ch[i],ch1[i]);
        }*/
        for(i=0,j=0;i<strlen(ch),j<strlen(ch1);i++,j++)
        {
            if(ch[i]==ch1[j])
            {
                p=1;
            }
            else
            {
                p=0;
                break;
            }
        }
        if(p==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

	//code
	return 0;
}
