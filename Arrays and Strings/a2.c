#include<stdio.h>
int main()
{
    int n,a[1000],i,k,c[10000];
    int min=0,temp;
    int j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        c[i]=k-a[i];
        if(c[i]<0)
        {
            c[i]=-c[i];
        }
    }
   /* for(i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }*/
    int temp1;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(c[j]>c[j+1])
            {
                temp1=c[j];
                c[j]=c[j+1];
                c[j+1]=temp1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
     printf("%d ",a[i]);
    }
}

