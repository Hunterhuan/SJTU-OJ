#include <iostream>
#include <cmath>
using namespace std;

int cost[15][15];    //城市间的开销
int dp[15][32768];  //动归的状态
int N;
int get_num_of1(int state) //计算一个整数的二进制中有多少个1，相当于状态中走过的城市个数
{
    int c = 0;
    while (state)
    {
        state = state&(state-1);
        c++;
    }
    return c;
}
int getc(int cur,int state)  //递归的过程
{
    if (dp[cur][state] > -1) return dp[cur][state];
    //state = ;  //去掉当前位
    if (get_num_of1(state) == 2) return dp[cur][state] = cost[cur][0];  //没有其他点要经过了
    int t = 2; //不算出发点
    int mini = 3000000;
    int tem;
    for (int i = 1;i < N;++i,t<<=1)
    {
        if (i==cur) continue;
        if (state & t)  //当前城市走过
        {
            tem = getc(i,state & (~(1<<cur))) + cost[i][cur]; //拿掉当前位
            if (tem < mini) mini = tem;
        }
    }
    return dp[cur][state] = mini;
}

int main(){
    cin>>N;

    for (int i = 0;i < N;++i) for (int j = 0;j < N;++j) cin>>cost[i][j];
    int num = pow(2,N);
    if (N==1)
    {
        cout<<0;
        return 0;
    }
    for (int i = 0;i < N;++i) for (int j= 0;j < pow(2,N);++j) dp[i][j] = -1; //初始化
    dp[0][1] = 0;
    int mini = 3000000;
    for (int i = 1;i < N;++i)  //从第i个城市返回出发点
    {
        int tem = cost[0][i] + getc(i,num-1);
        if (tem < mini) mini = tem;
    }
    cout<<mini;

    return 0;
}
