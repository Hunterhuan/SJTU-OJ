#include<iostream>
using namespace std;
unsigned int f[10005];//全局变量，自动初始化为0
unsigned int weight[1005];
unsigned int value[1005];
#define  max(x,y)   (x)>(y)?(x):(y)
int main()
{

    int N,M;
    cin>>M;
    cin>>N;
    for (int i=1;i<=N; i++)
    {
        cin>>weight[i]>>value[i];
    }
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
        {
            if (weight[i]<=j)
            {
                f[j]=max(f[j],f[j-weight[i]]+value[i]);
            }
        }

    cout<<f[M]<<endl;
}
