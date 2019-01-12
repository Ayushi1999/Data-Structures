#include<stdio.h>
int multiply(int num,int num1)
{
    int sum=0;
    while(num1>0)
    {
        if(num1&1 == 1)
            sum=sum+num;
        num=num<<1;
        num1=num1>>1;
    }
    return sum;
}
int main()
{
    int n,n1;
    scanf("%d %d",&n,&n1);
    int c=multiply(n,n1);
    printf("%d",c);
    return 0;
}
