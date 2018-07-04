#include <iostream>
using namespace std;
//not done
int main()
{
    int n;
    cin>>n;
    set<int> *element = new set<int>[n+1];
    int index[n+1];
    for(int i=1;i<=n;++i){
        cin>>index[i];
    }
    int tmp;
    for(int i=1;i<=n;++i){
        for(int j=0;j<index[i];++j){
            cin>>tmp;
            element.insert(tmp);
        }
    }
    int m;
    cin>>m;
    char t;
    int a,b;
    for(int i=0;i<m;++i){
        cin>>t>>a>>b;
        if(t=='+'){
            a.setunion(b);
        }
        else if(t=='-'){
            a.setdifferent(b);
        }
        else{
            a.setjoint(b);
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
