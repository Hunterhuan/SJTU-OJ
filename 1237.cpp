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
    int topSort()const
    {
        queue<int> q1;
        queue<int> q2;
        int res = 0;
        edgeNode * p;
        int *indegree = new int[Vers+1];
        for(int i=0;i<=Vers;++i)
            indegree[i] = 0;
        for(int i=1;i<=Vers;++i){
            for(p = verList[i].head;p!=NULL;p = p->next)
            {
                indegree[p->end_index]++;
            }
        }
        for(int i=1;i<=Vers;++i){
            if(indegree[i]==0)
                q1.push(i);
        }
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                int from_index = q1.front();
                q1.pop();
                for(p = verList[from_index].head;p!=NULL;p = p->next){
                    indegree[p->end_index]--;
                    if(indegree[p->end_index]==0)
                        q2.push(p->end_index);
                }
            }
            while(!q2.empty()){
                int tmp = q2.front();
                q2.pop();
                q1.push(tmp);
            }
            ++res;
        }
        return res;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    adjListGraph graph(n);
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph.insert(a,b);
    }
    cout<<graph.topSort();
    return 0;
}
