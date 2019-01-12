#include<stdio.h>
int rotate(int l,int r,int a[])
{
if(l>r)
return 0;
if(l==r)
return l;
int mid=(l+r)/2;
if(a[mid]>a[mid+1]&&mid<r)
    return mid+1;
if(a[mid]<a[mid-1]&&mid>l)
    return mid;
if(a[mid]>a[r])
    rotate(mid+1,r,a);
else
    rotate(l,mid,a);
}
int main()
{
int n,a[10000],i,k,l=0,u;
scanf("%d",&n);
//scanf("%d",&k);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
//int mid=(l+r)/2;
int t=rotate(l,r,a);
printf("%d",t);
}
