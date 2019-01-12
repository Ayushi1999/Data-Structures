#include<iostream>
using namespace std;
int main()
{
char str[20],str1[20],str2[20];
int i;
cin>>str;
for(i=0;i<strlen(str);i++)
{
str1[i]=str[i];
}
str1[i]='\0';
for(i=strlen(str)-1;i>=0;i--)
{
str2[i]=str[i];
}
str2[i]='\0';
if(strcmp(str1,str2))
{
cout<<palindrom";
}
else
{
cout<<"not";
}
return 0;
}
