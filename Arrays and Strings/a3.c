#include<stdio.h>
int main()
{
int arr[100],i,key=34,p=2,n;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
n=n+1;
for(i=n-1;i>=p;i--)
{
arr[i+1]=arr[i];
}
arr[p]=key;
for(i=0;i<n;i++)
{
    printf("%d ",arr[i]);
}
return 0;
}
