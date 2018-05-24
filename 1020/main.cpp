#include <iostream>

using namespace std;

int main()
{
    int number;

    cin>>number;

    cout<<number<<'=';
    int f=2;
    while(f*f<=number)
    {
        bool flag=false;
        int count = 0;
        while(!(number%f))
        {
            flag = true;
            number = number/f;
            ++count;
        }
        if(flag)
            cout<<f<<'('<<count<<')';
        ++f;
    }
    if(number>1)
        cout<<number<<"(1)";
    return 0;
}
