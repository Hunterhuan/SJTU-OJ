#include <iostream>
#include <vector>
using namespace std;

bool is(int number)
{
    int store = number;
    int result = 0;
    while(true)
    {
        int tmp = number%10;
        result = result + tmp*tmp*tmp;
        number = number/10;

        if(number==0)
            return result==store;
    }
}

int main()
{
    vector<int> result;
    int a,b;
    cin>>a>>b;
    if(a>b || a<=0 || b<=0)
    {
        cout<<"error";
        return 0;
    }
    for(int i=a;i<=b;++i)
    {
        if(is(i))
            result.push_back(i);
    }
    if(result.empty())
        cout<<"no";
    else
    {
        for(int i=0;i<result.size()-1;++i)
            cout<<result[i]<<endl;
        cout<<result[result.size()-1];
    }
    return 0;
}
