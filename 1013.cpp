#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;


// f[i] 就表示在i体积限制下，最高的价值

int f[10016];
int V, N;
int C[1016], W[1016];

int main(){
    cin>>V>>N;
    for(int i=0;i<N;++i)
        cin>>C[i]>>W[i];
    for(int i=0;i<N;++i){
        for(int j=1;j<=V;++j){
            if(j>=C[i]){
                f[j] = max(f[j], f[j-C[i]]+W[i]);
            }
        }
    }
    cout<<f[V]<<endl;
}
