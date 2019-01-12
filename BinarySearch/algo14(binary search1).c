#include<stdio.h>
int main()
{
    int n,m,a[1000],b[1000],i,l,r,mid;
    int arr[1000],k=0,no;
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
    for(i=0;i<m;i++)
    {
        no=b[i];
        l=0;
        r=n;
        while(l<r)
        {
            mid=(l+r)/2;
            if(no<a[mid])
            {
                r=mid;
            }
            else if(no>=a[mid])
            {
                l=mid+1;
            }
        }
        arr[k]=l;
        k++;
    }
    for(i=0;i<k;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
