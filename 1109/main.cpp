#include <iostream>
#include <list>
using namespace std;

struct person
{
    int number,a;
    person(int n,int ai)
    {
        number = n;
        a = ai;
    }
};
int main()
{
    int n;
    list<person> q;
    cin>>n;
    int tmp_a,tmp_c;
    for(int i=0;i<n;++i){
        cin>>tmp_a>>tmp_c;
        list<person>::iterator iter = q.begin();
        while(tmp_c>0 && iter!=q.end())
        {
            if(iter->a > tmp_a)
                break;
            ++iter;
            --tmp_c;
        }
        q.insert(iter,person(i+1,tmp_a));
    }
    for(list<person>::reverse_iterator iter=q.rbegin();iter!=q.rend();++iter){
        cout<<iter->number<<' ';
    }
    return 0;
}
