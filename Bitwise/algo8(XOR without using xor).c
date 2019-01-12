#include<stdio.h>
int XOR(int a,int b)
{
    int res=0,result,i;
    for(i=32;i>=0;i--)
    {
        int x=a&(1<<i);
        int y=b&(1<<i);
        if(x == y)
            result=0;
        else
            result=1;
        res=res<<1;
        res=res|result;
    }
    return res;
}
int main()
{
    int n,n1;
    scanf("%d %d",&n,&n1);
    int c=XOR(n,n1);
    printf("%d",c);
    return 0;
}

