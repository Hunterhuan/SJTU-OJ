#include <iostream>

using namespace std;

int main()
{
    int m;
    cin>>m;
    long long int n;
    for(int i=0;i<m;++i){
        cin>>n;
        if(n==0)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}
