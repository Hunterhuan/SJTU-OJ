#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> pq;

int N, M;
int main()
{
    cin>>N>>M;
    int first_M = M;
    if((N-1)%(M-1)!=0){
        first_M = (N-1)%(M-1)+1;
    }
    int tmp = 0;
    for(int i=0;i<N;++i){
        scanf("%d", &tmp);
        pq.push({tmp, tmp});
    }
    long long int ans = 0;
    vector<long long int> p;
    p.push_back(0);
    for(int i=0;i<first_M;++i){
        auto res = pq.top();
        pq.pop();
        p.push_back(res[0]);
        p[0] += res[0];
    }
    pq.push(p);
    ans += p[0];
    while(pq.size()>1){
        vector<long long int> q;
        q.push_back(0);
        for(int i=0;i<M;++i){
            auto r = pq.top();
            q[0] += r[0];
            pq.pop();
            for(int j=1;j<r.size();++j){
                q.push_back(r[j]);
                ans += r[j];
            }
        }
        pq.push(q);
    }
    cout<<ans<<endl;
    return 0;
}
