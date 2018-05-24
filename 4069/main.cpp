#include <iostream>

using namespace std;
char str[40];
int main()
{
    cin>>str;
    int count=0;
    char ch;
    cin>>ch;
    bool flag = false;
    while(str[count]!='\0')
    {
        if(str[count]==ch)
        {
            cout<<count<<' ';
            flag = true;
        }
        ++count;

    }
    if(!flag)
        cout<<"NULL";
    return 0;
}
