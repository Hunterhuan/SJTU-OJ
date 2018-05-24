#include <iostream>
#include <queue>
using namespace std;
int tree[1000005][2];
int main()
{
    int length;
    cin>>length;
    tree[0][0]=-1;
    tree[0][1] =-1;
    for(int i=1;i<length;++i)
    {
        int m;
        cin>>m;
        tree[i][0]=-1;
        tree[i][1]=-1;
        if(tree[m][0]==(-1))
            tree[m][0] = i;
        else
            tree[m][1] = i;
    }
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        if(tree[q.front()][0]!=(-1))
        {
            q.push(tree[q.front()][0]);
            if(tree[q.front()][1]!=(-1))
                q.push(tree[q.front()][1]);
        }
        cout<<q.front()<<' ';
        q.pop();
    }
    return 0;
}
