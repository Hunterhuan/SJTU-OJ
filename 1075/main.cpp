#include <iostream>
#include <cstring>
using namespace std;
//此题动归不太明白
int main(){
    int n,i,j;
    cin>>n;
    int num[n+10];
    memset(num,0,sizeof(num));
    num[0] = 1;
    num[1] = 1;
    for (int i = 2;i <= n;++i){
        num[i] += num[i-1];
        for (int j = 1;j < i;++j){
            num[i] += num[j-1]*num[i-j-1];
            num[i] %= 19301;
        }
    }
//    for (int i = 0;i <= n;++i) cout<<num[i]<<' ';cout<<endl;
    cout<<num[n];

    return 0;
}
