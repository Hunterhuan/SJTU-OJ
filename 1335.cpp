#include <iostream>
#include <algorithm>
using namespace std;
unsigned int res;
unsigned int q[10005];
int n;
bool comp(unsigned int a,unsigned int b)
{
    return a>b;
}
int main()
{
    res = 0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>q[i];
    sort(q+1,q+n+1,comp);
    for(int i=1;i<=n;++i)
    {
        res += i*q[i];
    }
    res -= q[n];
    cout<<res;
    return 0;
}
