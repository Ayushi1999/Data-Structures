#include<iostream>
using namespace std;
int swap(int a,int b)
{
int temp;
temp=a;
a=b;
b=temp;
cout<<"call by value"<<a <<b<<endl;
}
int swap1(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
cout<<"call by address"<<*a <<*b<<endl;
}
int swap2(int &a,int &b)
{
int temp;
temp=a;
a=b;
b=temp;
cout<<"call by refernce"<<a <<b<<endl;
}
int main()
{
int a,b;
cin>>a>>b;
swap(a,b);
//cout<<endl<<a<<b;
swap1(&a,&b);
cin>>a>>b;
swap2(a,b);
return 0;
}
