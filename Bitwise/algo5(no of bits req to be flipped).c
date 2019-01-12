#include<stdio.h>
int FlippedBits(int a,int b)
{
    int count=0;
    int d=(a^b);
    while(d)
    {
        if(d&1 == 1)
        {
        count++;
        }
        d=d>>1;
    }
    return count;
}
int main()
{
    int num,num1;
    scanf("%d %d",&num,&num1);
    int ans=FlippedBits(num,num1);
    printf("%d",ans);
}
