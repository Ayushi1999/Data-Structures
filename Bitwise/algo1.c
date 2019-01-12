#include<stdio.h>
int sign(int n)
{
    return (n>>31)|(!(!n));
}
int rightBitOff(int n)
{
    return n&(n-1);
}
int PowerOfFour(int n)
{
    int i=0,count=0;
    int count1=0;
    while(n!=0)
    {
        if((n&1)==0) {
            count++;
            //printf("%d ",)
        }
        else {
            count1++;
        }
        n=n>>1;
    }
    printf("%d %d",count,count1);
    if(count1 == 1 && count%2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int countSetBits(int n)
{
    int i=0,count=0;
    int c;
    while(n)
    {
        //c=(n&(1<<i));
        if(n&1 == 1)
        {
            count++;
        }
        n=n>>1;
       // n=n%2;
    }
    return count;
}
int TurnOffBit(int n,int k)
{
    return (n&~(1<<(k-1)));
}
int TurnOnBit(int n,int k)
{
    return (n|(1<<(k-1)));
}
int main()
{
    int a,b;
    int n,d;
    scanf("%d",&n);
    /*scanf("%d %d",&a,&b);
    d=(a^b)>>31;
    if(d == 1)
    printf("same sign");
    else
    printf("not");
    //int c=sign(n);
    //printf("%d",c);*/

   /* int t=rightBitOff(n);
    printf("%d",t);*/
  /* int t1=PowerOfFour(n);
    if(t1 == 1)
    {
        printf("power of four");
    }
    else
    {
        printf("not a power of four");
    }*/
    int k;
    scanf("%d",&k);
    int ans1=TurnOffBit(n,k);
    //printf("%d\n",ans1);
    int ans2=TurnOnBit(n,k);
    printf("%d",ans2);
   /* int u=countSetBits(n);
    printf("%d",u);*/
    return 0;
}
