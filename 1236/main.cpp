#include <iostream>
using namespace std;

struct edgeNode
{
    int end;
    int weight;
    edgeNode *next;

    edgeNode(int e,int w, edgeNode *p = NULL) :end(e),weight(w), next(p) {}
};

class adjList
{
private:
    edgeNode **verList;
    int vers;
public:
    adjList(int sz) :vers(sz), verList(new edgeNode*[sz + 1]()) {}
    ~adjList()
    {
        for (int i = 1;i <= vers;++i)
        {
            edgeNode *p = verList[i];
            while (p)
            {
                edgeNode *q = p->next;
                delete p;
                p = q;
            }
        }
        delete[]verList;
    }
    void insert(int u, int v, int w)
    {
        verList[u] = new edgeNode(v, w, verList[u]);
    }
    edgeNode *vat(int i)
    {
        return verList[i];
    }
};

int main()
{
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    int u, v, w;
    adjList graph(n);
    for (int i = 0;i < m;++i)
    {
        cin >> u >> v >> w;
        graph.insert(u, v, w);
    }
    int q[105];
    int back = -1;
    int front = 0;
    int distance[11];
    for (int i = 1;i <= n;++i)distance[i] = 0x7fffffff;
    distance[start] = 0;
    q[++back] = start;
    int cur;
    while (front <= back)
    {
        cur = q[front++];
        edgeNode *vert = graph.vat(cur);
        while (vert)
        {
            if (distance[cur] + vert->weight < distance[vert->end])
            {
                distance[vert->end] = distance[cur] + vert->weight;
                q[++back] = vert->end;
            }
            vert = vert->next;
        }
    }
    cout << distance[end] << endl;
    cin.get();
    cin.get();
    return 0;
}
