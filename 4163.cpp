#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;

// leetcode 410 hard
// 二分法去逼近这个结果。

int N, M;
int value[100005];
int sums[100005];

bool is_reach(int mid){
    int cur_sum = value[0];
    int sections = 1;
    for(int i=1;i<N;++i){
        cur_sum += value[i];
        if(cur_sum > mid){
            ++sections;
            cur_sum = value[i];
        }
    }
    if(sections > M)
        return false;
    return true;
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;++i){
        scanf("%d", &value[i]);
    }
    int low = value[0], high = value[0];
    for(int i=1;i<N;++i){
        low = max(low, value[i]);
        high += value[i];
    }
    int res = 0;
    while(low<high){
        int mid = (low + high)/2;
        if(is_reach(mid))
            high = mid;
        else
            low = mid +1 ;
    }
    cout<<low<<endl;
    return 0;
}
