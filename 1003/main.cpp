#include <iostream>
#include <queue>
using namespace std;
struct point
{
    int x;
    int y;
    point(int a ,int b){x = a;y = b;}
};
bool isillegal(int x,int y, int l)
{
    if(x<0 || y<0)
        return false;
    if(x>=l || y>=l)
        return false;
    return true;
}
int main()
{
    int p[101][101],l;
    int day=0;
    queue<point> bacterial;
    cin>>l;
    for(int i=0;i<l;++i)
    {
        for(int j=0;j<l;++j)
        {
            cin>>p[i][j];
            if(p[i][j]==1)
                bacterial.push(point(i,j));
        }
    }
    while(!bacterial.empty())
    {
        queue<point> bac_tmp;
        while(!bacterial.empty())
        {
        point tmp = bacterial.front();
        bacterial.pop();
        if(isillegal(tmp.x-1,tmp.y,l) && p[tmp.x-1][tmp.y]==0)
        {
            p[tmp.x-1][tmp.y] = 1;
            bac_tmp.push(point(tmp.x-1,tmp.y));
        }
        if(isillegal(tmp.x+1,tmp.y,l) && p[tmp.x+1][tmp.y]==0)
        {
            p[tmp.x+1][tmp.y] = 1;
            bac_tmp.push(point(tmp.x+1,tmp.y));
        }
        if(isillegal(tmp.x,tmp.y-1,l) && p[tmp.x][tmp.y-1]==0)
        {
            p[tmp.x][tmp.y-1] = 1;
            bac_tmp.push(point(tmp.x,tmp.y-1));
        }
        if(isillegal(tmp.x,tmp.y+1,l) && p[tmp.x][tmp.y+1]==0)
        {
            p[tmp.x][tmp.y+1] = 1;
            bac_tmp.push(point(tmp.x,tmp.y+1));
        }
        }
        day++;
        bacterial = bac_tmp;
        while(!bac_tmp.empty())
            bac_tmp.pop();
    }
    cout<<day-1;
    return 0;
}
