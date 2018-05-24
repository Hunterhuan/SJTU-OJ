#include <iostream>
#include <set>
using namespace std;
int N;
int n[102];
set<int> s[102];
void get_union(int a,int b)
{
    set_union()
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;++i)
        cin>>n[i];
    for(int i=1;i<=N;++i)
    {
        for(int j=0;j<n[i];++j)
        {
            int tmp;
            cin>>tmp;
            s[i].insert(tmp);
        }
    }

    cout << "Hello world!" << endl;
    return 0;
}
