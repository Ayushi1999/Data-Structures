#include<stdio.h>
//#include<stack>
void CalculateSpan(int a[],int span[])
{
    int i;
    stack<int>s;
    s.push(0);
    span[0]=1;
    for(i=1;i<7;i++)
    {
        while(arr[i]>=arr[s.top()])
        {
            s.pop();
        }
        span[i]=(s.empty())?(i+1):i-s.top();
        s.push(i);
    }
    for(i=0;i<7;i++)
    {
        cout<<span[i]<<" ";
        //printf("%d ",span[i]);
    }
}
int main()
{
int arr[7]={100,80,60,70,60,75,85};
int span[7];
CalculateSpan(arr,span);
}
