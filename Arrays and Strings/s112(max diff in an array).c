#include<stdio.h>
int main()
{
    int n,a[1000];
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int min=a[0];
    int max=-1;    //2 3 10 7 8 9 1
    for(i=1;i<n;i++)
    {
        if(a[i]-min>max)
        {
            max=a[i]-min;
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    printf("%d",max);
}
