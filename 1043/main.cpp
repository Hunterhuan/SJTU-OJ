#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int tree[1000005][2];

bool isleaf(int n)
{
    if(tree[n][0]==-1 &&tree[n][1]==-1)
        return true;
    else
        return false;
}
bool iscomplate()
{
    bool flag = false;
    int tmp;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        tmp = q.front();
        bool isleaves = isleaf(tmp);
        //cout<<tmp<<"is"<<isleaves<<"leaves"<<endl;
        if(!isleaves && flag)
            return false;
        if(isleaves)
            flag = true;
        else
        {
            q.push(tree[tmp][0]);
            if(tree[tmp][1]!=-1)
                q.push(tree[tmp][1]);
        }
        q.pop();
    }
    return true;
}
int main()
{
    memset(tree,-1,sizeof(tree));
    int n,tmp;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        cin>>tmp;
        if(tree[tmp][0]==-1)
        {
            tree[tmp][0]=i;
        }
        else{
            if(tree[tmp][0]>i){
                tree[tmp][1] = tree[tmp][0];
                tree[tmp][0] = i;
            }
            else{
                tree[tmp][1] = i;
            }
        }
    }
//    for(int i=0;i<10;++i)
//        cout<<tree[tmp][0]<<' '<<tree[tmp][1]<<endl;
    if(iscomplate())
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
