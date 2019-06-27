#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <set>


#define lowbit(a) ((a)&-(a))
using namespace std;

int a[10005];
int c[10005];

void update(int x, int y, int n){
    for(int i=x; i<=n; i+= lowbit(i)){
        c[i] += y;
    }
}

int getsum(int x, int n){
    int ans = 0;
    for(int i=x; i; i-= lowbit(i)){
        ans += c[i];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        update(i, tmp, n);
    }
    string query;
    int x,y;
    while(cin>>query){
        if(query=="end")
            return 0;
        cin>>x>>y;
        if(query=="query"){
            cout<<getsum(y,n)-getsum(x-1,n)<<endl;
        }else if(query=="inc"){
            update(x, y, n);
        }else if(query=="dec"){
            update(x, -y, n);
        }
    }
    return 0;
}
