#include<iostream>
using namespace std;
int length(char str[])
{
int count=0,i;
for(i=0;str[i]!='\0';i++)
{
count++;
}
return count;
}
int main()
{
char str[20],temp;
int y;
cin>>str;
y=length(str);
cout<<y;
return 0;
}
