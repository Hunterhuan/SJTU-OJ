#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int> l;
int n;
int main()
{
    cin>>n;
    int tmp;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&tmp);
        l.push_back(tmp);
    }
    sort(l.begin(),l.end());
    for(int i=0;i<n;++i)
        printf("%d ",l[i]);
    return 0;
}
