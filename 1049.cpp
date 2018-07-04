#include <iostream>
#include <stack>
using namespace std;

int T,N,M;
int train[1005];
bool legal(int N,int M)
{
    stack<int> station;
    int want = 0;
    int door = 0;
    while(true)
    {
        if(station.empty() && want==N )
        {
            return true;
        }
//        if(count==N && station.top()!=count2)
//            return false;
//        if(station.size()==M && station.top()!=count2 && train[count]!=count2)
//            return false;
        if(door==train[want])
        {
            door++;
            want++;
            continue;
        }
        else if(!station.empty() && station.top()==train[want])
        {
            station.pop();
            ++want;
            continue;
        }
        else
        {
            if(station.size()<M)
            {
                station.push(door);
                ++door;
            }
            else
                return false;
        }
    }
}
int main()
{
    cin>>T;
    for(int i=0;i<T;++i)
    {
        cin>>N>>M;
        for(int j=0;j<N;++j)
        {
            cin>>train[j];
        }
        if(legal(N,M))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
