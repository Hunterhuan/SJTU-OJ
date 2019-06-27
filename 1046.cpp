#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int tree[100005][3];
int numbers[100005];
bool colored[100005];
int res[100005];
int N;
int P;
int Q;

int compute_numbers(int root){
    if(root==0)
        return 0;
    if(tree[root][0]==0 && tree[root][1]==0){
        numbers[root] = 1;
        return 1;
    }
    numbers[root] = 1 + compute_numbers(tree[root][0]) + compute_numbers(tree[root][1]);
    return numbers[root];
}

void add(int leaf){
    if(leaf==0)
        return;
    res[leaf]++;
    add(tree[leaf][2]);
    return;
}

void color_it(int t, int x){
    int left = numbers[tree[t][0]];
    if(x<=left){
        color_it(tree[t][0], x);
    }else if(x>left+1){
        color_it(tree[t][1], x-left-1);
    }else{
        if(colored[t])
            return;
        else{
            colored[t]= true;
            add(t);
        }
    }
    return;
}

int main(){
    cin>>N>>P>>Q;
    int n;
    int left, right;
    int root = 0;
    for(int i=0;i<N;++i){
        scanf("%d", &n);
        scanf("%d", &left);
        scanf("%d", &right);
        tree[n][0] = left;
        tree[n][1] = right;
        tree[left][2] = n;
        tree[right][2] = n;
        root ^= n;
        root ^= left;
        root ^= right;
    }
    compute_numbers(root);
    int t, x;
    for(int i=0;i<P;++i){
        scanf("%d", &t);
        scanf("%d", &x);
        x = x%numbers[t] + 1;
        color_it(t, x);
    }

    for(int i=0;i<Q;++i){
        scanf("%d", &t);
        printf("%d\n", res[t]);
    }
    return 0;
}
