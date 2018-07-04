#include <iostream>

using namespace std;

int main()
{
    int result[10000];
    int l=0;
    int a,b;
    while(cin>>a>>b)
    {
        result[l]=a+b;
        ++l;
    }
    for(int i=0;i<l;++i)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
