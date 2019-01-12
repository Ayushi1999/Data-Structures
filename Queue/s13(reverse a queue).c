#include<iostream>
#include<queue>
/*struct queue
{
    int *arr;
};
struct queue* createQueue
{
    struct queue* q1=(struct queue*)malloc(sizeof(struct queue));
    q1->arr=(int*)malloc(sizeof(int)*1000);
    return q1;
};*/
void fun(queue<int>& qq)
{
    stack<int>ss;
    while(!qq.empty())
    {
        ss.push(qq.front());
        qq.pop();
    }
    while(!ss.empty())
    {
       // ss.pop();
        qq.push(ss.top());
        ss.pop();
        //int x=ss.pop();
        //printf("%d ",x);
    }
}
int main()
{
    queue<int>qq;
    qq.push(1);
    qq.push(2);
    qq.push(3);
    qq.push(4);
    qq.push(5);
    fun(qq);
}
