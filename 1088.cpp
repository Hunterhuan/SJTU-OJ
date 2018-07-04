#include <iostream>
#include <cmath>
using namespace std;

int cost[15][15];    //���м�Ŀ���
int dp[15][32768];  //�����״̬
int N;
int get_num_of1(int state) //����һ�������Ķ��������ж��ٸ�1���൱��״̬���߹��ĳ��и���
{
    int c = 0;
    while (state)
    {
        state = state&(state-1);
        c++;
    }
    return c;
}
int getc(int cur,int state)  //�ݹ�Ĺ���
{
    if (dp[cur][state] > -1) return dp[cur][state];
    //state = ;  //ȥ����ǰλ
    if (get_num_of1(state) == 2) return dp[cur][state] = cost[cur][0];  //û��������Ҫ������
    int t = 2; //���������
    int mini = 3000000;
    int tem;
    for (int i = 1;i < N;++i,t<<=1)
    {
        if (i==cur) continue;
        if (state & t)  //��ǰ�����߹�
        {
            tem = getc(i,state & (~(1<<cur))) + cost[i][cur]; //�õ���ǰλ
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
    for (int i = 0;i < N;++i) for (int j= 0;j < pow(2,N);++j) dp[i][j] = -1; //��ʼ��
    dp[0][1] = 0;
    int mini = 3000000;
    for (int i = 1;i < N;++i)  //�ӵ�i�����з��س�����
    {
        int tem = cost[0][i] + getc(i,num-1);
        if (tem < mini) mini = tem;
    }
    cout<<mini;

    return 0;
}
