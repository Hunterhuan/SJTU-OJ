#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;


class adjListGraph{
private:
    int Vers, Edges;

    struct edgeNode{
        int end_index;
        int weight;
        edgeNode *next;
        edgeNode(int e, int w, edgeNode *n = NULL)
        {
            end_index = e;
            weight = w;
            next= n;
        }
    };
    struct verNode{
        int ver;
        edgeNode *head;
        verNode(edgeNode *h = NULL){
            head = h;
        }
    };
    struct queueNode{
        int dist;
        int node;
        bool operator<(const queueNode &rp)const{return dist>rp.dist;}
    };
    verNode *verList;
public:
    adjListGraph(int vSize){
        Vers = vSize;
        Edges = 0;
        verList = new verNode[vSize+1];
        for(int i=0;i<=Vers;++i){
            verList[i].ver = i;
        }
    }

    bool insert(int u, int v, int w = 1){
        verList[u].head = new edgeNode(v,w,verList[u].head);
        ++Edges;
        return true;
    }

    bool remove(int u, int v){
        edgeNode *p = verList[u].head, *q;
        if(p==NULL)
            return false;
        if(p->end_index == v){
            verList[u].head = p->next;
            delete p;
            --Edges;
            return true;
        }
        while(p->next !=NULL)
        {
            if(p->next->end_index == v){
                q = p->next;
                p->next = p->next->next;
                delete q;
                --Edges;
                return true;
            }
            p = p->next;
        }
        return false;
    }


    bool exist(int u, int v)const {
        edgeNode *p = verList[u].head;
        while(p!=NULL)
        {
            if(p->end_index == v)
                return true;
            p = p->next;
        }
        return false;
        }
    ~adjListGraph(){
        edgeNode *p;
        for(int i=0;i<=Vers;++i)
            while((p = verList[i].head)!=NULL){
                verList[i].head=p->next;
                delete p;
            }
        delete [] verList;
    }
    void dijkstra(int start, int end) const{
        int * distance = new int[Vers+1];
        int *prev = new int [Vers+1];
        bool *known = new bool[Vers+1];
        int *steps = new int [Vers+1];
        priority_queue<queueNode> q;
        int u,sNo,i;
        edgeNode *p;
        int min;

        for(i = 0;i<Vers;++i){
            known[i] = false;
            distance[i] = INT_MAX;
            steps[i] = INT_MAX;
        }


        for(sNo = 0;sNo<Vers;++sNo)
        {
            if(verList[sNo].ver == start)
                break;
        }

        distance[sNo] = 0;
        prev[sNo] = sNo;
        steps[sNo] = 0;

        queueNode tmp;
        for(int k=0;k<Vers;++k){
            tmp.dist = distance[k];
            tmp.node = k;
            q.push(tmp);
        }
//        while(!q.empty()){
//            cout<<q.top().node<<' '<<q.top().dist<<endl;
//            q.pop();
//        }
        for(i=1;i<Vers;++i){
            while(!q.empty()){
                tmp = q.top();
                min = tmp.dist;
                u = tmp.node;
                if(known[u]){
                    q.pop();
                    continue;
                }
                else
                {
                    break;
                }
            }
            //cout<<u<<' '<<min<<endl;
            known[u] = true;
            for(p = verList[u].head; p !=NULL;p = p->next){
                if(!known[p->end_index]){
                    if(distance[p->end_index]>min + p->weight){
                        steps[p->end_index] = steps[u]+1;
                        distance[p->end_index] = min + p->weight;
                        prev[p->end_index] = u;
                        tmp.dist = distance[p->end_index];
                        tmp.node = p->end_index;
                        q.push(tmp);
                    }
                    else if(distance[p->end_index] == min + p->weight){
                        if(steps[u]+1<steps[p->end_index])
                        {
                            steps[p->end_index] = steps[u]+1;
                            distance[p->end_index] = min + p->weight;
                            prev[p->end_index] = u;
                        }
                    }
                }
            }
        }
        cout<<distance[end]<<endl;
        printPath(sNo,end,prev);

    }
    void printPath(int start, int end, int prev[])const{
        if(start==end){
            cout<<verList[start].ver;
            return;
        }
        printPath(start,prev[end],prev);
        cout<<" "<<verList[end].ver;
    }
};

int main()
{
    int n,m,start,end,a,b,p;
    cin>>n>>m>>start>>end;
    adjListGraph graph(n+1);
    for(int i=0;i<m;++i)
    {
        cin>>a>>b>>p;
        graph.insert(a,b,p);
    }
    graph.dijkstra(start,end);
    return 0;
}





#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <set>
#include <stack>

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int n,m,start, endpoint;
    int a,b,c;
    cin>>n>>m>>start>>endpoint;
    bool visited[n+1];
    int parents[n+1];
    memset(parents, -1, sizeof(parents));
    memset(visited, 0, sizeof(visited));
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[a].push_back(make_pair(a,c));
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 1, start, -1});
    int length = 0;
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        if(visited[tmp[2]])
            continue;
        visited[tmp[2]] = true;
        parents[tmp[2]] = tmp[3];
        if(tmp[2]==endpoint){
            length = tmp[0];
            break;
        }
        for(int i=0;i<graph[tmp[2]].size();++i){
            if(visited[graph[tmp[2]][i].first])
                continue;
            pq.push({tmp[0]+graph[tmp[2]][i].second, tmp[1]+1, graph[tmp[2]][i].first, tmp[2]});
        }
    }
    cout<<length<<endl;
    stack<int> s;
    while(endpoint!=-1){
        s.push(endpoint);
        endpoint = parents[endpoint];
    }
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}
