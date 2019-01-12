#include<stdio.h>
int BitXOR(int a,int b)
{
int f=a&b;
printf("%d",f);
unsigned int g=~f;
return g;
}
int main()
{
int a,b;
scanf("%d %d",&a,&b);
int c=BitXOR(a,b);
printf("%d",c);
return 0;
}
