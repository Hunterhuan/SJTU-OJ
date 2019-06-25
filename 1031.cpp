#include <iostream>
#include <queue>
using namespace std;

struct node{
    int raw;
    int col;
};

int n,map[101][101];  //地图边长及数据
bool bfs(int low,int);

int main(){
    int i,j,high,low,max=-1,min=120;
    cin>>n;
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j) {
            cin>>map[i][j];
            max = map[i][j]>max ? map[i][j]:max;
            min = map[i][j]<min ? map[i][j]:min;
        }
    high = max - min;
    low = 0;
    while (high>low+1) {
        int mid = (high+low)/2;
        bool flag = 0;
        for (i=min;i<=max-mid;++i) {
            if (bfs(i,i+mid)) {
                flag = true;
                break;
            }
        }
        if (flag) high = mid;
        else low = mid;
    }
    cout<<high;
    return 0;
}
bool bfs(int low,int high) {
    int to_x[4] = {-1,1,0,0},to_y[4] = {0,0,-1,1};  //便于扫描四周点
    bool state[101][101] = {0}; //判断是否已经扫描
    queue<node>open;  //待扫描队列
    if (map[1][1]<low || map[1][1]>high ||
        map[n][n]<low || map[n][n]>high) return false;
    node open_in,open_out;
    open_in.col = 1;
    open_in.raw = 1;
    open.push(open_in);
    state[1][1] = 1;
    while (open.size()>0) {
        open_out = open.front();
        open.pop();
        for (int i = 0;i < 4;++i) {  //向四周扫描
            int x = open_out.raw + to_x[i];
            int y = open_out.col + to_y[i];
            if (x<1 || x>n || y<1 || y>n) continue;
            if (map[x][y] >= low && map[x][y] <= high && state[x][y]==0) {
                if (x==n && y==n) return true;
                open_in.col = y;
                open_in.raw = x;
                open.push(open_in);
            }
            state[x][y] = 1;
        }
    }
    return false;
}