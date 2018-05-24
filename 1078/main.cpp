#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n,m;

struct Path
{
    int u,v,t;
};
vector<vector<Path> > path(200005);

int BFS(int S,long long dist[])
{
    bool vis[200005];
    memset(vis,0,sizeof(vis));
    vis[S]=true;
    int ans = 0;
    long long longest = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int tmp = q.front();
        for(int i=0;i<path[tmp].size();++i)
        {
            int v = path[tmp][i].v;
            int t = path[tmp][i].t;
            if(!vis[v])
            {
                dist[v] = t+dist[tmp];
                if(dist[v]>longest)
                {
                    ans = v;
                    longest = dist[v];
                }
                vis[v] = true;
                q.push(v);
            }
        }
        q.pop();
    }
    return ans;
}
long long dista[200005],distb[200005];
int main()
{
    int u,v,t;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>t;
        path[u].push_back(Path{u,v,t});
        path[v].push_back(Path{v,u,t});
    }
    int a = BFS(1,dista);
    memset(dista,0,sizeof(dista));
    int b = BFS(a,dista);
    BFS(b,distb);
    long long ans = 0;
    for(int i =0;i<=n;++i)
    {
        ans = max(ans,min(dista[i],distb[i]));
    }
    ans+=dista[b];
    cout<<ans<<endl;
    return 0;
}
