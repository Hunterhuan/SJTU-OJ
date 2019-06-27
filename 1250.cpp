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


const int MaxN = 100000+10;
//求最大平均的连续子列合 (至少连续F个元素) 考虑动态规划

int weight[MaxN]={0};//表示每个妹子的体重
int preSum[MaxN];//前缀和

int main(int argc, char const *argv[])
{

    int n,F;
    cin>>n>>F;
    preSum[0] = 0;
    for (int i = 1; i <= n; ++i){
        scanf("%d",&weight[i]);
        preSum[i] = preSum[i-1] + weight[i];
    }
    int ans = -1;
    //最后toCheck的部分是 j 到 i+F 的这段
    //核心思想就是 如果j到i这段是拉低了整个toCheck的部分 不如就不要了
    //上面这一个核心思想非常像二分答案里 判断是否存在大于等于F项连续和大于0的思想
     for (int i = 0, j = 0; i <= n - F; i++)
    {
        if (i > j && (preSum[i] - preSum[j]) * (i + F - j) < (preSum[i + F] - preSum[j]) * (i - j))
            j = i;//如果i和j之间的子段平均值小于i到i+f之间的平均值，则将舍弃i和j之间的子段
        if (ans < 1000 * (preSum[i + F] - preSum[j]) / (i + F - j))
            ans = 1000 * (preSum[i + F] - preSum[j]) / (i + F - j);
    }
    cout<<ans<<endl;
    return 0;
}
