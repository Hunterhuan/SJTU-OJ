#include <iostream>
#include <algorithm>
using namespace std;

int V,N;

int f[1005][10005] = {0};
int weight[1005],value[1005];

int max_value()
{
    for(int i=1;i<=N;++i)
        for(int v=1;v<=V;++v)
    {
        f[i][v] = 0;
        int ncount = v/weight[i];
        for(int k = 0;k<=ncount;++k)
        {
            f[i][v] = max(f[i][v],f[i-1][v-k*weight[i]]+k*value[i]);
        }
    }
    return f[N][V];
}
int main()
{
    cin>>V>>N;
    for(int i=1;i<=N;++i)
        cin>>weight[i]>>value[i];

    cout<<max_value();
    return 0;
}
