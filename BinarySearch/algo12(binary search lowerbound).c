#include<stdio.h>
int main()
{
    int n,i;
    int a[10000],no;
    int t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&no);
    int lb=0,ub=n-1;
    int mid;
    while(lb<ub) {    //lb is the index less than or equal to the given no.
        mid=(lb+ub)/2;
        if(no<=a[mid])
        {
          ub=mid;
        }
        else if(no>a[mid])
        {
            lb=mid+1;
        }
    }
    printf("%d",lb);
    }
    return 0;
}
