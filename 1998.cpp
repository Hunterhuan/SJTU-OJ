#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N;
int dis[100005];
int main()
{
    cin>>N;
    long long int ans = 0;
    for(int i=0;i<N;++i){
        scanf("%d", &dis[i]);
    }
    sort(dis, dis+N);
    int left = 0, right = N-1;
    while(left<right){
        ans += (dis[right--]-dis[left++]);
    }
    cout<<ans<<endl;
    return 0;
}
