#include <iostream>

using namespace std;
int high[1010];
int n;
int main()
{
    cin>>n;
    char q;
    if(n<=2)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        cin>>q;
        cin>>high[i];
    }
    cin>>q;
    int sum = 0;
    int max_high = -1,high_ind;
    for(int i=0;i<n;++i)
    {
        if(high[i]>=max_high)
        {
            high_ind = i;
            max_high = high[i];
        }
    }
    int start = 0;
    for(int i=0;i<high_ind;++i)
    {
        if(high[i]<high[start])
            sum = sum + high[start] - high[i];
        else
            start = i;
    }
    start = n-1;
    for(int i =n-1; i>high_ind;--i)
    {
        if(high[i]<high[start])
            sum = sum + high[start] - high[i];
        else
            start = i;
    }
    cout<<sum;
    return 0;
}
