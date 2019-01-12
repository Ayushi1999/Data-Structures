#include<stdio.h>
int main()
{
    int n,i,j,temp;
    int a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n/2;i++)  //no of cycles
    {
        for(j=i;j<n-1-i;j++)  //no of rotations
        {
            temp=a[i][j];
            a[i][j]=a[n-1-j][i];
            a[n-1-j][i]=a[n-1-i][n-1-j];
            a[n-1-i][n-1-j]=a[i+j][n-1];
            a[i+j][n-1]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
