#include<iostream>
using namespace std;
void pop()
{
    if(!q1.empty())
        return;
    else
        q1.pop();
}
int top()
{
    return q1.front();
}
void push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    queue<int>q=q2;
    q2=q1;
    q1=q2;
}
int main()
{
    //queue<int>q1,q2;
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top();
    s.pop();
}
