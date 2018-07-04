#include <iostream>
#include <list>
using namespace std;


int main()
{
    int N,M;
    cin>>N>>M;
    list<int> l;
    for(int i=0;i<N;++i)
    {
        int tmp;
        cin>>tmp;
        l.push_back(tmp);
    }

    for(int i=0;i<M;++i)
    {
        int tmp;
        cin>>tmp;
        if(tmp==1)
        {
            int tmp2,tmp3;
            cin>>tmp2>>tmp3;
            list<int>::iterator it = l.begin();
            for(int j=0;j<tmp2;++j)
                ++it;
            l.insert(it,tmp3);
        }
        else
        {
            int tmp2;
            cin>>tmp2;
            list<int>::iterator it = l.begin();
            for(int j=1;j<tmp2;++j)
                ++it;
            l.erase(it);
        }
    }
    for(list<int>::iterator it = l.begin();it!=l.end();++it)
        cout<<*it<<' ';
    return 0;
}
