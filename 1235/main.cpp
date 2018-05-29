#include <iostream>
#include <queue>
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
        bool operator<(const queueNode &rp)const{return dist<rp.dist;}
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
    void dijkstra(int start, int noEdge) const{
        int * distance = new int[Vers+1];
        int *prev = new int [Vers+1];
        bool *known = new bool[Vers+1];
        int sNo,i;
        edgeNode *p;
        priority_queue<queueNode> q;
        queueNode minn,succ;
        for(i = 1;i<=Vers;++i){
            known[i] = false;
            distance[i] = noEdge;
        }

        for(sNo = 1;sNo<=Vers;++sNo)
            if(verList[sNo].ver == start)
                break;
        distance[sNo] = 0;
        prev[sNo] = sNo;
        minn.dist = 0;
        minn.node = sNo;
        q.push(minn);

        while(!q.empty()){
            minn = q.top();
            q.pop();
            if(known[minn.node])continue;
            known[minn.node] = true;
            for(p = verList[minn.node].head; p!=NULL ; p = p->next){
                if(!known[p->end_index] && distance[p->end_index] > minn.dist+p->weight){
                    succ.dist = distance[p->end_index] = minn.dist+p->weight;
                    prev[p->end_index] = minn.node;
                    succ.node = p->end_index;
                    q.push(succ);
                }
            }
        }
        for(i = 1;i<=Vers;++i){
            cout<<"从"<<start<<"到"<<verList[i].ver<<"的路径为:"<<endl;
            printPath(sNo,i,prev);
            cout<<"\t长度为:"<<distance[i]<<endl;
        }
    }
private:
    void printPath(int start, int end, int prev[])const{
        if(start==end){
            cout<<verList[start].ver;
            return;
        }
        printPath(start,prev[end],prev);
        cout<<"-"<<verList[end].ver;
    }
};

int main()
{
    int n,m,start,end,a,b,p;
    cin>>n>>m>>start>>end;
    adjListGraph graph(n);
    for(int i=0;i<m;++i)
    {
        cin>>a>>b>>p;
        graph.insert(a,b,p);
    }
    graph.dijkstra(start,end);
    return 0;
}
