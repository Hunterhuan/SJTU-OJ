#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
using namespace std;

priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
vector<vector<int>> f;

int compute(int i, int x){
    int res = 0;
    res += x*x*f[i][0];
    res += x*f[i][1];
    res += f[i][2];
    return res;
}

int main()
{
    int n, k;
    cin>>n>>k;
    f.resize(n);
    int a,b,c;
    double middle;
    for(int i=0;i<n;++i){
        scanf("%d %d %d", &a, &b, &c);
        f[i].push_back(a);
        f[i].push_back(b);
        f[i].push_back(c);
        middle = b/double(-2*a);
        pq.push({compute(i, floor(middle)), i, floor(middle), 0});
        pq.push({compute(i, floor(middle)+1), i, floor(middle)+1, 1});
    }
    while(k--){
        auto v = pq.top();
        pq.pop();
        cout<<v[0]<<' ';
        if(v[3]==0){
            pq.push({compute(v[1], v[2]-1), v[1], v[2]-1, 0});
        }else{
            pq.push({compute(v[1], v[2]+1), v[1], v[2]+1, 1});
        }
    }
    return 0;
}
