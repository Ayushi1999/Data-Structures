#include<stdio.h>
void func1(int x,int y,int(*a)[x][y])
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
             printf("%d ",*(*(*a+i)+j));
          //  printf("%d ",(*a)[i][j]);
        }
        printf("\n");
    }
}
void func2(int x,int y,int (*a)[y])
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
}
void func3(int *a,int x,int y)
{
    int i,j;
    for(i=0;i<x*y;i++)
    {
        for(j=0;j<x*y;j++)
        {
            printf("%d ",(*a+i)+j);
       //    printf("%d",*(a+j)+i*y))
        }
        printf("\n");
    }
}
int main()
{
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    func1(3,3,&arr);
    func2(3,3,arr);
    func3(*arr,3,3);
}
