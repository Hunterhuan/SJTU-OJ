#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
char c[1005];
int count_n[4];
int main()
{
    cin.get(c,1005);
    int index = 0;
    s.push(0);
    while(c[index]!='\0')
    {
        //cout<<index<<' ';
        if(c[index]=='<')
        {
            if(c[index+1]=='/')
            {
                s.pop();
                if(c[index+2]=='r')
                    index +=6;
                else if(c[index+2]=='b')
                    index +=7;
                else
                    index +=9;
            }
            else if(c[index+1]=='b')
            {
                s.push(3);
                index +=6;
            }
            else if(c[index+1]=='r')
            {
                s.push(1);
                index +=5;
            }
            else{
                s.push(2);
                index +=8;
            }
        }
        else if((c[index]<='z'&&c[index]>='a')||(c[index]<='Z'&&c[index]>='A'))
        {
            count_n[s.top()]++;
            index++;
        }
        else
        {
            ++index;
        }
    }
    cout<<count_n[1]<<' ';
    cout<<count_n[2]<<' ';
    cout<<count_n[3]<<endl;
    return 0;
}
