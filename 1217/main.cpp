#include <iostream>
#include <algorithm>
using namespace std;
int num[2505];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    int m;
    cin>>m;
    int tmp;
    int j;
    for(int i=0;i<m;++i){
        cin>>tmp;
        for(j=0;j<n;++j){
            if(tmp==num[j])
            {
                cout<<"Y"<<endl;
                break;
            }
        }
        if(j==n)
            cout<<"N"<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
