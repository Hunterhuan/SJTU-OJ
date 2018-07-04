#include <iostream>

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

    int find(int start , int m) const{
        int num = 0;
        bool *visited = new bool [Vers+1];
        int *stack = new int [m+1];
        int top_index = 0;

        for(int i=0;i<=Vers;++i){
            visited[i] = false;
        }
        find(start,m,top_index,visited, stack, num);
        return num;
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

private:
    void find(int start, int m, int &top, bool visited[], int st[], int &num)const{
        edgeNode *p = verList[start].head;
        visited[start] = true;
        st[top++] = start;
        // if stack is full.
        if(top == m+1){
            ++num;
            visited[start] = false;
            --top;
            return;
        }
        while( p != NULL){
            if(!visited[p->end_index])
                find(p->end_index, m, top, visited, st, num);
            p = p->next;
        }
        visited[start] = false;
        --top;
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    int start, M;
    cin>>start>>M;
    int a, b;
    adjListGraph Graph(n);
    for(int i=0;i<m;++i){
        cin>>a>>b;
        Graph.insert(a,b);
    }
    int res = Graph.find(start, M);
    cout<<res;
    return 0;
}
