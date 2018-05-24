#include <iostream>
#include <algorithm>

using namespace std;
int N;
int x[100005];
int main()
{
    long long int res=0;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>x[i];
    //cout<<x[0]<<x[1]<<x[2];
    sort(x,x+N);
    for(int i=0;i<N/2;++i)
    {
        res = res + (x[N-i-1]-x[i]);
    }
    cout << res << endl;
    return 0;
}
