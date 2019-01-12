#include<iostream>
using namespace std:
int main()
{
char str[20],c[20];
int i,count=0;
cin>>str;
for(i=0;str[i]!='\0';i++)
{
count=0;
for(j=0;str[j]!='\0';j++)
{
if(str[i]==str[j])
{
count++;
}
}
c[i]=count;
cout<<str[i]<<" "<<c[i];
}
return 0;
}
