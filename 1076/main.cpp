#include <iostream>
#include <queue>
using namespace std;
int N,Q;
int fruit[102][102];
int tree[102][2];

int most_fruit(queue<int> q,int n)
{
    queue<int> new
}

int main()
{
    cin>>N>>Q;
    for(int i =0 ;i<N;++i)
    {
        int m,n,p;
        cin>>m>>n>>p;
        if(tree[m][0]==0)
            tree[m][0] = n;
        else
            tree[m][1] = n;
        fruit[m][n] = fruit[n][m] = p;
    }
    queue<int> q;
    q.push_back(1);
    cout<<most_fruit(1,Q);


    return 0;
}
