#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int R,C;//行数和列数
int Map[500+10][500+10] = {0}; //记录高度
int res[500+10][500+10] = {0};
int dx[4] = {+1,-1,0,0};
int dy[4] = {0,0,+1,-1};
int ans = 0;//最终结果

void init(){
    cin>>R>>C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            scanf("%d",&Map[i][j]);

}

int dfs(int x,int y){
    if(res[x][y] > 0)//如果计算过
        return res[x][y];
    int max = 0;
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        //周围四个点里的 比(x,y)矮的 且res最大的那个作为此点的后续
        if(newx<=R && newx>=1 && newy<=C && newy>=1){
            if(Map[newx][newy] < Map[x][y]){
                int tmp = dfs(newx,newy);
                max = tmp > max ? tmp : max;
            }
        }
    }
    res[x][y] = max + 1;
    return res[x][y];
}

int Build(){
    int ans = 0;
    for (int i = 1; i <= R; ++i){
        for (int j=1; j <= C; ++j){
            ans = dfs(i,j) > ans ? res[i][j] : ans;
        }
    }
    return ans;
}

int main()
{
    init();
    cout<<Build()<<endl;
    return 0;
}
