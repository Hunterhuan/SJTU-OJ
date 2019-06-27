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

int N, M;
int dis[200005];

int search_lower(int *array, int size, int key){
    int first = 0, middle;
    int half, len = size;
    while(len>0){
        half = len >>1;
        middle = first + half;
        if(array[middle]<key){
            first = middle + 1;
            len = len-half -1;
        }
        else if(array[middle]==key){
            return middle;
        }else{
            len = half;
        }
    }
    return first;
}


int main()
{
    cin>>N>>M;
    for(int i=0;i<N;++i){
        scanf("%d", &dis[i]);
    }
    sort(dis, dis+N);
    int t;
    int res = 0;
    for(int i=0;i<M;++i){
        scanf("%d", &t);
        int pos = search_lower(dis, N, t);
        if(pos==0){
            res = abs(t-dis[0]);
        }
        else if(pos == N){
            res = abs(t-dis[N-1]);
        }else{
            res = min(abs(t-dis[pos]), abs(t-dis[pos-1]));
        }
        printf("%d\n", res);
    }
}
