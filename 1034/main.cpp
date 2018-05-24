#include <iostream>
#include <cstdio>
using namespace std;

int RP[200000+1000];//存储RP
int front = 0;
int rear = 0;
int que[200005];
bool empty(){
    return front==rear;
}

void q_out(int x){
    if(que[front]==x)
        front++;
}

void q_in(int x){
    //入队时删除所有比它小的元素
    while(!empty()){
        if(que[rear-1]<x)
            rear--;
        else
            break;
    }
    que[rear++] = x;
}

void print(){
    for (int i = front; i < rear; ++i)
    {
        cout<<que[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{

    int N,K; //添加环形变化后 长度为N+K-1
    int ans = 0;
    scanf("%d%d",&N,&K);
    for (int i = 1; i <= N; ++i){
        scanf("%d",&RP[i]);
        if(i<=K-1){
            RP[N+i] = RP[i];
        }
    }
    //初始化ans
    for (int i = 1; i <= K; ++i)
    {
        if(ans < RP[i])
            ans = RP[i];
        q_in(RP[i]);
    }
    for (int i = K+1; i <= N+K-1; ++i)
    {
        q_out(RP[i-K]);
        q_in(RP[i]);
        //print();
        if(que[front] < ans)
            ans = que[front];
    }

    cout<<ans<<endl;
    return 0;
}
