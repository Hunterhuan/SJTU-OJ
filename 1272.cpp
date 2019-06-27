#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int main()
{
    map<int, int> m;
    int n;
    if(n<=1){
        cout<<n<<endl;
        return 0;
    }
    cin>>n;
    vector<int> v(n,0);
    int tmp;
    queue<int> q;
    for(int i=0;i<n;++i){
        cin>>tmp;
        m[tmp]++;
        v[i] = tmp;
        q.push(tmp);
    }
    int a,b;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i<v.size();++i){
            if(v[i]==t)
                continue;
            a = max(v[i], t);
            b = min(v[i], t);
            if(!m.count(a/b)){
                m[a/b]++;
                q.push(a/b);
                v.push_back(a/b);
            }
        }
    }
    cout<<v.size()<<endl;
    return 0;
}
