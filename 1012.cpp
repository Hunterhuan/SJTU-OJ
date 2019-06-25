#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int S, T;
    cin>>S>>T;
    vector<int> length(T-S+1,1);
    vector<long long int> times(T-S+1, 1);
    int ans = 1;
    long long int maxtimes = 0;
    for(int i=S;i<=T;++i){
        for(int j=1;j<=100;++j){
            if(i*j%100!=0)
                continue;
            if(i*j/100+i>T)
                break;
            if(length[i-S]+1>length[i*j/100+i-S]){
                length[i*j/100+i-S] = length[i-S]+1;
                times[i*j/100+i-S] = times[i-S];
            }
            else if(length[i-S]+1==length[i*j/100+i-S]){
                times[i*j/100+i-S] += times[i-S];
            }
        }
        if(length[i-S]>ans){
            ans = length[i-S];
            maxtimes = times[i-S];
        }
        else if(length[i-S]==ans){
            maxtimes += times[i-S];
        }
    }
    cout<<ans<<endl;
    cout<<maxtimes<<endl;
}
