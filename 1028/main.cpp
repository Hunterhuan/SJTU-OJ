#include <iostream>
#include <stack>
using namespace std;

int N;

int main()
{
    cin>>N;
    char instruction[10];
    bool res = true;
    bool flag = false;
    stack<int> ins;
    int count = 0;
    string a[N];
    for(int i=0;i<N;++i)
    {
        string tmp;
        cin>>tmp;
        if(tmp[0]=='t')
        {
            if(a[count-1][0]=='i')
                a[count-1] += tmp;
            else
            {
                res = false;
                break;
            }
        }
        else
        {
            a[count] = tmp;
            ++count;
        }
    }
    int start = 0, end = count-1;
    while(start<=end)
    {

    }


//    for(int i=0;i<N;++i){
//        cin>>instruction;
//        if(instruction[0]=='i')
//        {
//            flag = true;
//            ins.push(1);
//            continue;
//        }
//        if(flag)
//        {
//            if(instruction[0]=='t')
//            {
//                flag = false;
//                continue;
//            }
//            else
//            {
//                res = false;
//                break;
//            }
//        }
//        if(instruction[0]=='b'){
//            ins.push(2);
//            continue;
//        }
//        if(instruction[1]=='n'){
//            if(ins.empty())
//            {
//                res = false;
//                break;
//            }
//            else
//            {
//                    while(true)
//                    {
//                        if(ins.empty() || ins.top()==2)
//                            break;
//                        ins.pop();
//                    }
//                    if(ins.empty())
//                    {
//                        res = false;
//                        break;
//                    }
//                    if(ins.top()==2)
//                    {
//                        ins.pop();
//                        continue;
//                    }
//            }
//
//        }
//        if(instruction[1]=='l')
//        {
//            if(ins.empty()|| ins.top()!=1)
//            {
//                res = false;
//                break;
//            }
//        }
//    }
//    while(!ins.empty())
//    {
//        if(ins.top()==2)
//            res = false;
//        ins.pop();
//    }
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
