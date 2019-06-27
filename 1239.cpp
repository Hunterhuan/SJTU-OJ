#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dic = {{1500,3}, {3000,10}, {4500,20}, {26000,25},
                            {20000, 30}, {25000, 35}, {200000,45}};

int main()
{
    int n;
    cin>>n;
    float res = 0;
    n -= 3500;
    if(n<=0){
        cout<<res<<endl;
        return 0;
    }
    for(int i=0;i<dic.size();++i){
        if(n<=dic[i][0]){
            res += float(n*dic[i][1])/100;
            cout<<int(res)<<endl;
            return 0;
        }else{
            res += float(dic[i][0] * dic[i][1])/100;
        }
        n -= dic[i][0];
    }
    cout<<0<<endl;
    return 0;
}
