#include <iostream>
#include <algorithm>
using namespace std;
int number[10005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>number[i];
    }
    sort(number,number+n);
    for(int i=0;i<n;++i)
        cout<<number[i]<<' ';
    return 0;
}
