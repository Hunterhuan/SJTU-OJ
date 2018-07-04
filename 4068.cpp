#include <iostream>
#include <queue>
using namespace std;
queue<char> q[40];
int n;
int main()
{
    char newdata[40];
    cin>>n;
    cin>>newdata;
    int data_length;
    for(int i=0;i<40;++i)
    {
        if(newdata[i]=='\0')
        {
            data_length = i;
            break;
        }
    }
    int count = 0;
    bool flag=true;
    if(n==1)
    {
        cout<<newdata;
        return 0;
    }
    for(int i=0;i<data_length;++i)
    {
        if(count==0)
        {
            flag=true;
            q[0].push(newdata[i]);
            ++count;
            continue;
        }
        if(count==n-1)
        {
            flag =false;
            q[n-1].push(newdata[i]);
            --count;
            continue;
        }
        if(flag==true)
        {
            q[count].push(newdata[i]);
            ++count;
        }
        else
        {
            q[count].push(newdata[i]);
            --count;
        }
    }
    for(int i=0;i<n;++i)
    {
        while(!q[i].empty())
        {
            cout<<q[i].front();
            q[i].pop();
        }
    }
    return 0;
}
