#include<stdio.h>
void func1(int *ptr,int n)
{
    int i,j;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(*(ptr+j)<*(ptr+j+1))
            {
                temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
            }
        }
    }
   /* for(i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
    }*/
    printf("\n");
    i=0;
    j=n-1;
       while(i<j)
       {
        printf("%d ",*(ptr+i));
        printf("%d ",*(ptr+j));
        i++;
        j--;
       }
       if(n%2!=0)
       {
           printf("%d",*(ptr+i));
       }
}
int main()
{
int n,a[1000];
int i;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
func1(a,n);
return 0;
}
