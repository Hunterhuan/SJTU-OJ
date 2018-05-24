#include <iostream>
#include <iomanip>

using namespace std;

void getMatrix(int begin ,int l,int count, int mountain[155][155])
{
    if(l<=0)
        return;
    for(int i=0;i<l;++i)
    {
        mountain[count][count+i] = begin;
        ++begin;
    }
    for(int i=0;i<l-1;++i)
    {
        mountain[count+i+1][count+l-1] = begin;
        ++begin;
    }
    for(int i=0;i<l-1;++i)
    {
        mountain[count+l-1][count+l-2-i] = begin;
        ++begin;
    }
    for(int i=0;i<l-2;++i)
    {
        mountain[count+l-2-i][count] = begin;
        ++begin;
    }
    l = l - 2;
    getMatrix(begin,l,count+1,mountain);
}
int main()
{
    int l;
    cin>>l;
    int mountain[155][155];
    getMatrix(1,l,1,mountain);
    for(int i=1 ; i<=l;++i)
    {
        for(int j=1;j<=l;++j)
            cout<<setw(6)<<mountain[i][j];
        cout<<endl;
    }
    return 0;
}
