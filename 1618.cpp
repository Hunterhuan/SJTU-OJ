#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits.h>
#include<cstdio>
#include<cstring>
#define maxn 100010

int queue[maxn];
int maxqueue[maxn];
int minqueue[maxn];
int q1,maq1,miq1;
int q2,maq2,miq2;

void init(){
	 q1 = 1,maq1 = 1,miq1 = 1;
	 q2 = 1,maq2 = 1,miq2 = 1;
}

void push(int x){
	queue[q1++] = x;
	while(maxqueue[maq1-1] < x&&maq1 > maq2){
		maq1--;
	}
	maxqueue[maq1++] = x;
	while(minqueue[miq1-1] > x&&miq1 > miq2){
		miq1--;
	}
	minqueue[miq1++] = x;
	return ;
}

void pop(){
	if(q1<=q2){printf("EMPTY!\n"); return;}
	int ans = queue[q2++];
	if(maxqueue[maq2] == ans) maq2++;
	if(minqueue[miq2] == ans) miq2++;
	return ;
}

int MIN(){
	if(miq2==miq1){printf("EMPTY!\n");return 0;}
    return minqueue[miq2];
}

int MAX(){
	if(maq2==maq1){printf("EMPTY!\n");return 0;}
	return maxqueue[maq2];
}
int N, K;
int min_res[100005], max_res[100005];
int main(){
    scanf("%d %d", &N, &K);
    int tmp;
    for(int i=0;i<K;++i){
        scanf("%d", &tmp);
        push(tmp);
    }
    min_res[0] = MIN();
    max_res[0] = MAX();
    for(int i=K; i<N;++i){
        scanf("%d", &tmp);
        push(tmp);
        pop();
        min_res[i-K+1] = MIN();
        max_res[i-K+1] = MAX();
    }
    for(int i=0;i<N-K+1;++i){
        printf("%d ",min_res[i]);
    }
    printf("\n");
    for(int i=0;i<N-K+1;++i){
        printf("%d ",max_res[i]);
    }
	return 0;
}
