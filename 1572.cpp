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
#include <stack>

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;

int dp[100005];
int tmp[100005];

int helper(int left, int right){
    if(right-left<=1)
        return 0;
    int middle = (left+right)/2;
    int res = 0;
    res += helper(left, middle);
    res += helper(middle, right);
    for(int i=left;i<middle;++i){
        tmp[i-left] = dp[i];
    }
    int cnt = left;
    int len_a = middle-left;
    int len_b = right-middle;
    int cnt1 = 0, cnt2 = 0;
    while(cnt<right){
        if(cnt1==len_a){
            break;
        }
        if(cnt2==len_b){
            dp[cnt++] = tmp[cnt1++];
            res += len_b;
            continue;
        }
        if(tmp[cnt1]<dp[cnt2+middle]){
            dp[cnt++] = tmp[cnt1++];
            res += cnt2;
        }else{
            dp[cnt++] = dp[cnt2+middle];
            cnt2++;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>dp[i];
    }
    cout<<helper(0, n);
    return 0;
}
