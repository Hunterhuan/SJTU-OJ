#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int compute_distance(int a, int b, int n){
    vector<bool> visited(n,false);
    queue<vector<int>> q;
    for(int i=1;i<=n;++i){
        if(graph[a][i] != -1)
            q.push({i, graph[a][i]});
    }
    visited[a] = true;
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        if(tmp[0]==b)
            return tmp[1];
        for(int i=1;i<=n;++i){
            if(graph[tmp[0]][i] != -1 && visited[i]==false){
                q.push({i, tmp[1] + graph[tmp[0]][i]});
            }
        }
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
    graph.assign(n+1, vector<int>(n+1,-1));
    for(int i=0;i<n-1;++i){
        int a, b, c;
        cin>>a>>b>>c;
        graph[a][b] = c ;
        graph[b][a] = c;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;++i){
        int a, b;
        cin>>a>>b;
        if(a==b)
            cout<<0<<endl;
        else
            cout<< compute_distance(a,b, n)<<endl;
    }
    return 0;
}
