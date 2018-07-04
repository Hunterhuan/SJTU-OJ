#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int res[1005][1005];
int LCS(int m,int n)
{
    if(m==0 || n==0)
        return 0;
    else
    {
        if(a[m-1]==b[n-1])
        {
            if(res[m-1][n-1]==0)
                res[m-1][n-1] = LCS(m-1,n-1);
            return res[m-1][n-1]+1;
        }
        else
        {
            if(res[m-1][n]==0)
                res[m-1][n] = LCS(m-1,n);
            if(res[m][n-1]==0)
                res[m][n-1] = LCS(m,n-1);
            return max(res[m-1][n],res[m][n-1]);
        }
    }
}
int main()
{

    cin>>a>>b;
    cout<<LCS(a.length(),b.length());
    return 0;
}
