#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int,int> sets[20005];
bool comp(pair<int,int> a,pair<int,int>b)
{
    return a.first<b.first;
}
int main()
{
    int count=0;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>sets[i].first>>sets[i].second;
    }
    sort(sets,sets+N,comp);
    int begin = sets[0].first,end = sets[0].second;
    for(int i=1;i<N;++i)
    {
        if(sets[i].first>end)
        {
            count = count+end-begin;
            begin = sets[i].first;
            end = sets[i].second;
        }
        else if(sets[i].second>end)
        {
            end = sets[i].second;
        }
    }
    cout<<(count = count+end-begin);
    return 0;
}
