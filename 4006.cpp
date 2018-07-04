#include <iostream>
#include <algorithm>
using namespace std;
bool done[600];
bool cmp(int *q,int *p)
{
    return q[1]>p[1];
}
int main()
{
    int n;
    cin>>n;
    int **ti = new int*[n];
    for(int i=0;i<n;++i)
    {
        ti[i] = new int[2];
        cin>>ti[i][0];
    }
    for(int i=0;i<n;++i)
        cin>>ti[i][1];
    sort(ti,ti+n,cmp);
    int res = 0;
    for(int i=0;i<n;++i)
    {
        int done_time = ti[i][0];
        for(int j=done_time;j>0;--j)
        {
            if(!done[j])
            {
                done[j] =true;
                res += ti[i][1];
                break;
            }
        }
    }
    cout<<res;
    return 0;
}
