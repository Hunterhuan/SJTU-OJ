#include <iostream>
#include
using namespace std;
char a[600],b[600];



int main()
{
    cin>>a>>b;
    int end_a,end_b;
    for(int i=0;i<600;++i)
    {
        if(a[i]=='\0')
        {
            end_a = i;
            break;
        }
    }
    for(int i=0;i<600;++i)
    {
        if(b[i]=='\0')
        {
            end_b = i;
            break;
        }
    }

    return 0;
}
