#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m,n;
    int M[10005],N[10005];
    int count=0;
    cin>>m>>n;
    for(int i=0;i<m;++i)
        cin>>M[i];
    for(int i=0;i<n;++i)
        cin>>N[i];
    sort(M,M+m);
    sort(N,N+n);
    int p=m-1,q=n-1;
    while(p>=0 && q>=(-1))
    {
        if(M[p]>N[q] && q>=0)
        {
            count = count+2;
            --p;
            --q;
        }
        else
        {
            if(q==(-1))
            {
                count++;
                --p;
            }
            else
            {
                --q;
            }
        }
    }
    cout<<count;
    return 0;
}
