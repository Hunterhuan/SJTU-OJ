#include <iostream>

using namespace std;

int main()
{
    int total_time, far,U,F,D,i;
    cin>>total_time>>far>>U>>F>>D;
    char tmp;
    for(i=0;i<far;++i)
    {
        cin>>tmp;
        if(tmp=='u' || tmp=='d')
            total_time=total_time-U-D;
        else
            total_time = total_time-F-F;
        if(total_time<0)
        {
            cout<<i;
            break;
        }
    }
    if(i==far)
        cout<<far;
    return 0;
}
