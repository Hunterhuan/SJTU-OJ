#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_match(const string &str)
{
    size_t len = str.length();
    stack<char> s;
    int i;
    for (i = 0; i < len; ++i) {
        if (str[i] == '(') {
            s.push(str[i]);
            continue;
        }
        if (str[i] == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
                continue;
            }
        }
    }

    if (!s.empty()) {
        return false;
    }

    return true;
}
int main()
{
    string a;
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>a;
        if(is_match(a))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}





#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

char para[102];
int main(){
    int n;
    cin>>n;
    while(n--){
        memset(para, 0, sizeof(para));
        cin>>para;
        int count = 0;
        for(int i=0;i<101;++i){
            if(para[i]=='(')
               ++count;
            else if(para[i]==')'){
                --count;
                if(count<0){
                    cout<<"NO"<<endl;
                    break;
                }
            }else{
                if(count==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
                break;
            }
        }
    }
    return 0;
}
