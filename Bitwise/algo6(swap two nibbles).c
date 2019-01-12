#include<stdio.h>
int swapTwoNibbles(int n)
{
    return ((n & 15)<<4 | (n & 15)>>4);
}
int main()
{
    int n;
    scanf("%d",&n);
    int ans=swapTwoNibbles(n);
    printf("%d",ans);
    return 0;
}
