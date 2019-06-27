#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


vector<vector<int>> activaties;
int N;
int main()
{
    cin>>N;
    activaties.assign(N, vector<int>(2,0));
    for(int i=0;i<N;++i){
        cin>>activaties[i][1]>>activaties[i][0];
    }
    sort(activaties.begin(), activaties.end());
    int lastendtime = -1;
    int cnt = 0;
    for(int i=0;i<N;++i){
        if(activaties[i][1]>=lastendtime){
            ++cnt;
            lastendtime = activaties[i][0];
        }
    }
    cout<<cnt<<endl;
    return 0;
}
