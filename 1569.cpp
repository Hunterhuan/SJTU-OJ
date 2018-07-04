#include <iostream>

using namespace std;
int N;
int nb[10002];

void inc(int a,int b)
{
    for(int i=a;i<=N;++i)
    {
        nb[i] += b;
    }
}

void dec(int a,int b)
{
    for(int i= a;i<=N;++i)
    {
        nb[i] -= b;
    }
}

int query(int a, int b)
{
    return nb[b]-nb[a-1];
}

int main()
{
    cin>>N;
    cin>>nb[1];
    nb[0] = 0;
    for(int i=2;i<=N;++i)
    {
        cin>>nb[i];
        nb[i] = nb[i] + nb[i-1];
    }
    char stru[10];
    int a,b;
    while(true)
    {
        cin>>stru;
        if(stru[0]=='q')
        {
            cin>>a>>b;
            cout<<query(a,b)<<endl;
        }
        else if(stru[0]=='i')
        {
            cin>>a>>b;
            inc(a,b);
        }
        else if(stru[0]=='d')
        {
            cin>>a>>b;
            dec(a,b);
        }
        else
            break;
    }
    return 0;
}
