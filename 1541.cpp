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

int num[200005];
int max_q[200005];


void push_to_q(int x, int &left, int &right){
    while(right>left){
        if(max_q[right-1]<x){
            right--;
        }else{
            break;
        }
    }
    max_q[right++] =x;
}

int max_of_q(int &left){
    return max_q[left];
}

void pop_q(int x, int &left){
    if(max_q[left]==x){
        ++left;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    int left = 0, right = 0;
    cin>>k>>n;
    for(int i=0;i<n;++i)
        cin>>num[i];
    for(int i=0;i<k;++i){
        push_to_q(num[i], left, right);
    }
    cout<<max_of_q(left)<<' ';
    for(int i=0;i<n-k;++i){
        pop_q(num[i], left);
        push_to_q(num[i+k], left, right);
        cout<<max_of_q(left)<<' ';
    }
    return 0;
}
