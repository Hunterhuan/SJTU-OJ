#include <iostream>
#include <math.h>
using namespace std;

bool isPrime_2( int num )
{
     int tmp =sqrt( num);
     for(int i= 2;i <=tmp; i++)
        if(num %i== 0)
          return 0 ;
     return 1 ;
}

int main()
{
    int n;
    cin>>n;
    int start = n-1,end = n+1;
    if(isPrime_2(n))
        cout<<0<<endl;
    else
    {
        for(;start>=0;--start)
        {
            if(isPrime_2(start))
                break;
        }
        for(;true;++end)
        {
            if(isPrime_2(end))
                break;
        }
        cout<<end-start<<endl;
    }
    return 0;
}
