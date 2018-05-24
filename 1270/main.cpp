#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[100005];
int main()
{
    int f=0;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n/2;++i)
        f += a[n-1-i]-a[i];
    cout<<f;
    return 0;
}
