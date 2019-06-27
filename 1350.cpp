#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;
vector<vector<int>> points;


int main()
{
    int n;
    cin>>n;
    if(n<=2){
        cout<<n<<endl;
        return 0;
    }
    points.resize(n);
    int a, b;
    vector<unordered_map<double, int>> m(n);
    int res_max = 2;
    int tmp;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        points[i].push_back(a);
        points[i].push_back(b);
        for(int j=0;j<i;++j){
            a = points[i][0] - points[j][0];
            b = points[i][1] - points[j][1];
            if(b==0){
                tmp = ++m[j][-1];
                res_max = max(res_max, tmp);
            }else{
                tmp = ++m[j][abs(double(a)/b)];
                res_max = max(res_max, tmp);
            }
        }
    }
    cout<<++res_max<<endl;
    return 0;
}
