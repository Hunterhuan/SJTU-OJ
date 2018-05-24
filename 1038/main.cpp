#include <iostream>

using namespace std;
int monkey[10005];
int M;

int search(int k,int start)
{
    int count = 0;
    while(count<k)
    {
        if(start > M )
            start = 1;
        if(monkey[start] ==0 )
        {
            ++count;
            if(count==k)
            {
                monkey[start] = 1;
                return ++start;
            }
        }
        ++start;
    }
}
int main()
{
    cin>>M;
    int begin = 1;
    for(int i=0;i<M-1;++i)
    {
        int tmp;
        cin>>tmp;
        tmp = tmp%(M-i);
        if(tmp==0)
            tmp = M-i;
        begin = search(tmp,begin);
    }
    for(int i=1;i<=M;++i)
    {
        if(monkey[i]==0)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
