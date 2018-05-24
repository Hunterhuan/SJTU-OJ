#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int tree[1055][3];
int n;
int build_tree()
{
    cin>>n;
    ++n;
    n = n/2;
    --n;
    for(int i=0;i<n;++i){
        int tmp,tmp1,tmp2;
        cin>>tmp>>tmp1>>tmp2;
        tree[tmp][1] = tmp1;
        tree[tmp][2] = tmp2;
        tree[tmp1][0] = tmp;
        tree[tmp2][0] = tmp;
    }
}

int find_root()
{
    int root = 1;
    while(tree[root][0]!=-1){
        root = tree[root][0];
    }
    return root;
}

void display()
{
    for(int i=1;i<=7;++i)
        cout<<tree[i][0]<<' '<<tree[i][1]<<' '<<tree[i][2]<<endl;
}

int main()
{
    memset(tree,-1,sizeof(tree));
    build_tree();
    //display();
    int root = find_root();
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout<<tmp<<endl;
        int left = tree[tmp][1];
        int right = tree[tmp][2];
        if(left!=-1)
            q.push(left);
        if(right!=-1)
            q.push(right);
    }
    return 0;
}
