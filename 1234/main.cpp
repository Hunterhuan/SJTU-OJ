#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
void quickSort(T s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r;
        T x = s[l];
        while (i < j)
        {
            while(i < j && !(s[j]< x)) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}

class disjointSet
{
private:
    int *parent;
public:
    disjointSet(int n) :parent(new int[n + 1])
    {
        for (int i = 1;i <= n;++i) parent[i] = -1;
    }
    ~disjointSet() { delete[]parent; }
    int Find(int x)
    {
        if (parent[x] < 0)return x;
        else
        {
            int tmp = parent[x];
            while (parent[tmp] > 0)tmp = parent[tmp];
            int y;
            while (x != tmp)
            {
                y = parent[x];
                parent[x] = tmp;
                x = y;
            }
            return tmp;
        }
    }
    void Union(int root1, int root2)
    {
        if (root1 == root2)return;
        if (parent[root1] < parent[root2])
        {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
        else
        {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
};


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
    struct edge{
        int begin_index, end_index;
        int w;
        bool operator<(const edge &rp)const{
            return w<rp.w;
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
    int kruskal()const{
        int edgesAccepted = 0, u , v;
        edgeNode *p;
        disjointSet ds(Vers);
        edge pq[Edges+1];
        int index=0;

        for(int i=0;i<Vers;++i){
            for(p = verList[i].head; p!=NULL; p = p->next){
                if(i<p->end_index){
                    pq[index].begin_index = i;
                    pq[index].end_index = p->end_index;
                    pq[index].w = p->weight;
                    ++index;
                }
            }
        }
        quickSort(pq,0,index-1);
        int tmp = 0;
        int ans = 0;
        while(edgesAccepted <Vers -1){
            edge e = pq[tmp];
            ++tmp;
            u = ds.Find(e.begin_index);
            v = ds.Find(e.end_index);
            if(u!=v){
                ans += e.w;
                edgesAccepted++;
                ds.Union(u,v);
                //cout<<"("<<verList[e.begin_index].ver<<','<<verList[e.end_index].ver<<")\t";
            }
        }
        return ans;
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    int a,b,p;
    adjListGraph graph(n);
    for(int i=0;i<m;++i){
        cin>>a>>b>>p;
        graph.insert(a,b,p);
        graph.insert(b,a,p);
    }
    cout<<graph.kruskal();
    return 0;
}
