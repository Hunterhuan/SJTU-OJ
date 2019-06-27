#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int A,B,C;

vector<vector<pair<int,int>>> graph;

int distances[20005];

bool visited[20005];

void bfs(int start){
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    while(!q.empty()){
        auto s = q.size();
        for(int i=0;i<s;++i){
            auto p = q.front();
            q.pop();
            for(auto j: graph[p.first]){
                if(visited[j.first])
                    continue;
                visited[j.first] = true;
                q.push(make_pair(j.first, j.second+p.second));
                distances[j.first] += (j.second+p.second);
            }
        }
    }
}


int main()
{
    scanf("%d %d %d %d", &N, &A, &B, &C);
    graph.resize(N+1);
    int u, v, w;
    for(int i=1;i<N;++i){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    bfs(A);
    bfs(B);
    bfs(C);
    int res = -1;
    int least = INT_MAX;
    for(int i=1;i<=N;++i){
        if(distances[i]<least){
            least = distances[i];
            res = i;
        }
    }
    cout<<res<<endl<<least<<endl;
    return 0;
}
