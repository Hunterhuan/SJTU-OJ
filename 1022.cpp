#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    n = n %2040;
    int a = 1, b = 1;
    if(n<=2){
        cout<<1<<endl;
        return 0;
    }
    int tmp;
    for(int i=3;i<=n;++i){
        tmp = (a + b)%2010;
        a = b;
        b = tmp;
    }
    cout<<b<<endl;
    return 0;
}
