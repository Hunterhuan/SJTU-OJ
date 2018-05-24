#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long long int a=0,b=0;
    char tmp;
    string str;
    while(true)
    {
        tmp = cin.get();
        if(tmp>='0'&&tmp<='9'){
            a = a*10+(tmp-'0');
            if(a>=100000000)
            {
                cin>>str;
                cout<<"Large";
                return 0;
            }
        }
        else if(tmp=='+')
            break;
    }
    while(true)
    {
        tmp = cin.get();
        if(tmp>='0'&&tmp<='9'){
            b = b*10+(tmp-'0');
            if(b>=100000000)
            {
                cin>>str;
                cout<<"Large";
                return 0;
            }
        }
        else if(tmp=='\n')
            break;
    }
    long long int c = a+b;
    if(c>=100000000)
        cout<<"Large";
    else
        cout<<c;
    return 0;
}

