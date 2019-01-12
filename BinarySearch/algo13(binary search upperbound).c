#include<stdio.h>
int main()
{
    int n,i;
    int a[10000],no;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&no);
    int lb=0,ub=n-1;
    int mid;
    while(lb<ub) {
        mid=(lb+ub)/2;   //ub is first greater element than the given no
        if(no>=a[mid])
        {
          lb=mid+1;
        }
        else if(no<a[mid])
        {
            ub=mid;
        }
    }
    printf("%d",lb);
    return 0;
}

