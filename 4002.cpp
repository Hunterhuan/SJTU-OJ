#include <iostream>

using namespace std;
bool matrix[10][50][50];
int n,m;


bool islegal(int x,int y)
{
    return (x<n&&y<m);
}
int get_max()
{
    int max_size = 0;
    for(int k=0;k<10;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[k][i][j])
                {
                    int v=0;
                    while(islegal(i+v,j+v))
                    {
                        if(matrix[k][i+v][j+v]&&matrix[k][i][j+v] && matrix[k][i+v][j])
                        {
                            max_size = max(max_size,v);
                        }
                        ++v;
                    }
                }
            }
        }
    }
    return max_size;
}

int main()
{
    cin>>n>>m;
    int tmp;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>tmp;
            matrix[tmp][i][j]=1;
        }
    }
    tmp = get_max()+1;
    cout<<tmp*tmp;
    return 0;
}
