#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
// dp[i][j]表示在前i个活动可以选择时，体力值为j时，最大的智力值是多少

struct act
{
    int dh;
    int dw;
};

// state dp[400+5];
int dp[400+5][32000+50]={0};
act acts[500+5];
int n;//一共的活动数目

void init(){
    cin>>n;
    for (int i = 0; i <= n; ++i)
    {
        cin>>acts[i].dh>>acts[i].dw;
    }//注意acts[0]存储的是初始情况

}

void build(){
    //初始化为负无穷 以来判断智力值是转化来的 还是根本没有被利用
    memset(dp,-50000,sizeof(dp));

    dp[0][acts[0].dh] = acts[0].dw;//初始化
    int curMax = 31000+50;//固定的curMax 注意31000 = 30000+1000

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= curMax; ++j)
        {

            if(j >= acts[i].dh and dp[i-1][j-acts[i].dh] > -50000){
                //体力值大于0 且 智力值是有效的
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-acts[i].dh]+acts[i].dw);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int res = 0;
    //找到最大的
    for (int j = 1; j <= curMax; ++j)
    {
        if(dp[n][j] > 70){
            res = max(res,dp[n][j] * j);
        }
    }
    if(res)
        cout<<res<<endl;
    else
        cout<<"Death"<<endl;
}

int main(int argc, char const *argv[])
{
    init();
    build();
    return 0;
}
