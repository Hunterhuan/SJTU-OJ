#include <iostream>
#include <limits.h>
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
    adjList(int sz) :vers(sz), verList(new edgeNode*[sz + 1]())
    {}
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
    int spath(int start, int end)
    {
        int q[150];
        int back = 0, front = 0;

        int distance[vers+1];
        for (int i = 1;i <= vers;++i)
            distance[i] = INT_MAX;
        distance[start] = 0;
        q[back] = start;

        int cur_ver;
        while (front <= back)
        {
            cur_ver = q[front++];
            edgeNode *ver = verList[cur_ver];
            while (ver)
            {
                if (distance[cur_ver] + ver->weight < distance[ver->end])
                {
                    distance[ver->end] = distance[cur_ver] + ver->weight;
                    ++back;
                    q[back] = ver->end;
                }
                ver = ver->next;
            }
        }
        return distance[end];
    }
};

int main()
{
    int n, m;
    int start, end;
    cin >> n >> m >> start >> end;
    int a, b, p;
    adjList graph(n);
    for (int i = 0;i < m;++i)
    {
        cin >> a >> b >> p;
        graph.insert(a, b, p);
    }
    int res = graph.spath(start, end);
    cout<<res;
    return 0;
}
