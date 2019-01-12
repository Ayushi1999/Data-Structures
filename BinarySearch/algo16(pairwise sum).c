#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,t=0,no,l,r,mid,mid1,count=0,i,k,p,j=0;
    int *b=(int*)malloc(sizeof(int)*10000);
    int *a=(int*)malloc(sizeof(int)*10000);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        no=k-a[i];
        int l=i+1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(no<=a[mid])
            {
                r=mid;
            }
            else if(no>a[mid])
            {
                l=mid+1;
            }
        }
        int l1=i+1,r1=n;
        while(l1<r1)
        {
             int mid1=(l1+r1)/2;
            if(no<a[mid1])
            {
                r1=mid1;
            }
            else if(no>=a[mid1])
            {
                l1=mid1+1;
            }
        }
        p=r1-l;
        if(p>0)
        {
            printf("%d\n",no);
            //j++;
        }
        count+=p;
    }
    printf("%d",count);
    return 0;
}
