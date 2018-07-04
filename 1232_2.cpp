#include <iostream>
using namespace std;

int N;
int start, End;
bool *mark;
bool **access;
int *path;
int pos = 0;

class disjointSet
{
private:
    int *parent;
public:
    disjointSet(int n)
    {
        parent = new int[n + 1];
        for (int i = 1;i <= n;++i)
            parent[i] = -1;
    }
    ~disjointSet()
    {
        delete[]parent;
    }
    int find(int x)
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

int get_row(int P)
{
    int l = 1, r = N;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if ((mid*(mid + 1) >> 1) < P)l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int get_col(int x, int y)
{
    return ((x*(x - 1) >> 1) + y);
}

bool find_path(int x, int y)
{
    mark[get_col(x,y)] = true;
    if (get_col(x, y) == End)
        return true;
    if (access[0][get_col(x, y)] && !mark[get_col(x - 1, y - 1)])
    {
        if (find_path(x-1,y-1))
        {
            path[pos++] = get_col(x - 1, y - 1);
            return true;
        }
    }
    if (access[1][get_col(x, y)] && !mark[get_col(x - 1, y)])
    {
        if (find_path(x-1,y))
        {
            path[pos++] = get_col(x - 1, y);
            return true;
        }
    }
    if ( access[2][get_col(x, y)] && !mark[get_col(x + 1, y)])
    {
        if (find_path(x+1,y))
        {
            path[pos++] = get_col(x + 1, y);
            return true;
        }
    }
    if (access[3][get_col(x, y)] && !mark[get_col(x + 1, y + 1)])
    {
        if (find_path(x+1,y+1))
        {
            path[pos++] = get_col(x + 1, y + 1);
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> start >> End;
    int Pos, dir;
    int x, y;
    access = new bool*[4];
    for(int i=0;i<4;++i)
        access[i] = new bool[(N*(N + 1) >> 1) + 1]();
    disjointSet s(N*(N + 1) >> 1);
    while (cin >> Pos >> dir)
    {
        x = get_row(Pos);
        y = Pos - (x*(x - 1) >> 1);
        switch (dir)
        {
        case 0:
            if (y != 1)
            {
                s.Union(s.find(Pos), s.find(Pos - x));
                access[0][Pos] = access[3][Pos - x] = true;
            }
            break;
        case 1:
            if (y != x)
            {
                s.Union(s.find(Pos), s.find(Pos - x + 1));
                access[1][Pos] = access[2][Pos - x + 1] = true;
            }
            break;
        case 2:
            if (x != N)
            {
                s.Union(s.find(Pos), s.find(Pos + x));
                access[2][Pos] = access[1][Pos + x] = true;
            }
            break;
        case 3:
            if (x != N)
            {
                s.Union(s.find(Pos), s.find(Pos + x + 1));
                access[3][Pos] = access[0][Pos + x + 1] = true;
            }
        }
        if (s.find(start) == s.find(End))
            break;
    }
    x = get_row(start);
    y = start - (x*(x - 1) >> 1);
    mark = new bool[(N*(N + 1) >> 1) + 1]();
    path = new int[(N*(N + 1) >> 1)]();
    if (find_path(x, y))
        path[pos++] = start;
    for (int i = pos - 1;i >= 0;--i)
        cout << path[i] << ' ';
    cout << '\n';
    return 0;
}
