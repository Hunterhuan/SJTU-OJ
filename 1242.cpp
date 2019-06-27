#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
using namespace std;



int main()
{
    int a, b;
    cin>>a>>b;
    int res = 0;
    vector<bool> isprime(b+1,false);
    for(int i=2;i<=b;++i){
        if(isprime[i]==true)
            continue;
        int tmp = 2;
        while(tmp*i<=b){
            isprime[tmp*i] = true;
            ++tmp;
        }
        if(i>=a)
            ++res;
    }
    cout<<res<<endl;
    return 0;
}
