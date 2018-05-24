#include <iostream>

using namespace std;
int fi[2041];

int fib(int n)
{
    fi[1] = 1;
    fi[2] = 1;
    if(n==1 || n==2)
        return 1;
    for(int i=3;i<=2040;++i)
    {
        fi[i] = (fi[i-1]+fi[i-2])%2010;
        if(i==n)
            return fi[i];
    }
}
int main()
{
    long long N;
    cin>>N;
    int n = N%2040;
    if(n==0)
        n=2040;
    cout<<fib(n);
    return 0;
}
