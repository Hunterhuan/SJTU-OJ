#include <iostream>
#include <algorithm>

//Ç°×ººÍ
using namespace std;
int l,w;
int p[1005][1005];
//void display()
//{
//    for(int i=0;i<=l;++i)
//    {
//        for(int j=0;j<=w;++j)
//            cout<<p[i][j]<<' ';
//        cout<<endl;
//    }
//}
int main()
{
    cin>>l>>w;
    int a,b;

    for(int i=1;i<=l;++i)
    {
        for(int j=1;j<=w;++j)
        {
            int tmp;
            cin>>tmp;
            p[i][j] = tmp;
            p[i][j] = p[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }
    cin>>a>>b;
    int max_number = 0;
    for(int i = a;i<=l;++i)
    {
        for(int j=b;j<=w;++j)
        {
            int tmp = p[i][j] + p[i-a][j-b] -p[i-a][j]-p[i][j-b];
            max_number = max(max_number,tmp);
        }
    }
    cout<<max_number;
    return 0;
}
