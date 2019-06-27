#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
using namespace std;



int main()
{
    int N;
    cin>>N;
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
    for(int i=1;i<=N;++i){
        for(int j=0;j<=i;++j){
            vector<int> v = {j,i};
            pq.push(make_pair(double(j)/i, v));
        }
    }
    double lastone = -1;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        if(t.first == lastone){
            continue;
        }
        auto v = t.second;
        string  res = "";
        res = res +  to_string(v[0]) + '/' + to_string(v[1]);
        cout<<res<<endl;
        lastone = t.first;
    }
    return 0;
}
