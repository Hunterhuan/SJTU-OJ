#include <iostream>
#include <queue>
#define maxsize 12350
using namespace std;

struct node
{
    int next, right;
};

int index[maxsize] = {0};
node tree[maxsize];
queue<int> q;

void preorder(int root)
{
    cout << root << ' ';
    if (tree[root].next > 0)
        preorder(tree[root].next);
    if (tree[root].right > 0)
        preorder(tree[root].right);
}

void postorder(int root)
{
    if (tree[root].next > 0)
        postorder(tree[root].next);
    cout << root << ' ';
    if (tree[root].right > 0)
        postorder(tree[root].right);
}

void level(int root)
{
    int node;
    q.push(root);
    while (q.size())
    {
        node = q.front();
        q.pop();
        for (; node > 0; node = tree[node].right)
        {
            cout << node << ' ';
            if (tree[node].next > 0)
                q.push(tree[node].next);
        }
    }
}

int main()
{
    int n, x, c, s, root;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> c >> s;
        tree[x].next = c;
        tree[x].right = s;
        index[c] = 1;
        index[s] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if (index[i] == 0)
        {
            root = i;
            break;
        }
    preorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    level(root);
    return 0;
}
