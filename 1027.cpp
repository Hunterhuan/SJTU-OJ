#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


int main()
{
    int n,Max,s,N;
    cin>>n>>Max>>s;
    N = n;
    map<int, Fly> fly;
    int fid = 0;
    while(n-->0){
        int in,out,repStay;
        cin>>in>>out>>repStay;
        pq.push({in, out, repStay, fid});
        fid++;
    }
    int res[N];
    auto lastone = pq.top();
    pq.pop();
    int downtime = lastone[0] + lastone[1];

    while(pq.size()>0){
        auto tmp = pq.top();
        pq.pop();
        if(lastone[0] == tmp[0])
    }
    for(int i=0;i<N;i++)
        cout<<res[i]<<" "<<endl;
    return 0;
}