#include<stdio.h>
int main()
{
int n,m,a[1000],b[10000],i,j,v[10000],count;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
scanf("%d",&m);
for(i=0;i<m;i++)
{
scanf("%d",&b[i]);
}
i=0;
int k=0;
for(j=0;j<m;j++)
{
    count=0;
    i=0;
while(i<n)
{
    if(a[i]<=b[j])
    {
    count++;
    }
    i++;
}
printf("%d",count);
}
return 0;
}
