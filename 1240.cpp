#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
vector<long long int> res(3,0);

int main()
{
    int n;
    cin>>n;
    res[0] = 1;
    for(int i=0;i<n;++i){
        long long int tmp = res[2] + res[1];
        res[2] += res[1];
        res[1] = res[0];
        res[0] = tmp;
    }
    cout<<res[2]+res[1]+res[0]<<endl;
    return 0;
}
