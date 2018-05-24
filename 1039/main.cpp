#include <iostream>
#include <cstring>
using namespace std;

int N;
int a[30005][2];
int num[60000];
void shunxu(int root,int nodenum)
{
    if(a[root][0]!=-1)
        shunxu(a[root][0],nodenum<<1);
    if(a[root][1]!=-1)
        shunxu(a[root][1],nodenum<<1|1);
    num[root] = nodenum;
}
void back_bianli(int root)
{
    if(a[root][0]!=-1)
        back_bianli(a[root][0]);
    if(a[root][1]!=-1)
        back_bianli(a[root][1]);
    cout<<root<<' ';
}

int main()
{
    cin>>N;
    int tmp1,tmp2,tmp3;
    for(int i=0;i<N;++i){
        cin>>tmp1>>tmp2>>tmp3;
        a[tmp1][0] = tmp2;
        a[tmp1][1] = tmp3;
    }
    num[1] = 1;
    shunxu(1,1);
    for(int i=1;i<=N;++i)
        cout<<num[i]<<' ';
    cout<<endl;
    back_bianli(1);
    return 0;
}
