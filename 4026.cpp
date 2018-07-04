#include <iostream>

using namespace std;
char number[10];
int main()
{
    cin>>number;
    for(int i=0;i<4;++i)
    {
        if(number[i]=='\0')
        {
            cout<<"Error!";
            return 0;
        }
        int tmp = number[i]-'0';
        tmp = tmp+13;
        number[i] = 'A'+tmp-1;
    }
    cout<<number;
    return 0;
}
