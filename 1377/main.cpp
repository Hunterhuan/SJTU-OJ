#include <iostream>
#include <cstring>
using namespace std;
int num[100005];
int matrix[100005];
int N;
int M;
int main()
{
    int res=0;
    cin>>N>>M;
    int index,tmp;
    for(int i=0;i<N;++i)
    {
        cin>>tmp;
        num[i] = tmp;
        if(tmp==M)
            index = i;
    }
    tmp = 0;
    for(int j=index+1;j<N;++j)
    {
        if(num[j]>M)
            ++tmp;
        else
            --tmp;
        matrix[j] = tmp;
    }
    tmp=0;
    for(int j=index-1;j>=0;--j)
    {
        if(num[j]>M)
            ++tmp;
        else
            --tmp;
        matrix[j] = tmp;
    }
    for(int i=0;i<=index;++i)
    {
        for(int j=index;j<N;++j)
        {
            if(matrix[i]+matrix[j]==0)
                res++;
        }
    }
    cout<<res;
    return 0;
}
