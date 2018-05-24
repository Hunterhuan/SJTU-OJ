#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[32];


int count_1(int n)
{
    int count=0;
    for(int i=0;i<32;++i)
    {
        if(n&0x01)
            ++count;
        n = n>>1;
    }
    return count;
}

int main()
{
    int n,k;
    cin>>n>>k;
    if(n<=k)
    {
        cout<<k-n;
        return 0;
    }
    int tmp = n;
    int count=count_1(n);
    while(count>k)
    {
        for(int i=0;i<32;++i)
        {
            if((n>>i)&0x01)
            {
                n = n + (0x01<<i);
                count = count_1(n);
                break;
            }
        }
    }
    cout<<n-tmp;
    return 0;
}
