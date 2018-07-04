#include <iostream>

using namespace std;

int main()
{
    int money[12];
    double all=0,save = 0;
    for(int i=0;i<12;++i)
        cin>>money[i];
    for(int i=0;i<12;++i)
    {
        all = all+300;
        all = all-money[i];
        if(all<0)
        {
            cout<<-1*(i+1);
            return 0;
        }
        int n = all/100;
        save = save+ n*100;
        all = all-n*100;
    }
    all = all+save*1.2;
    cout <<all;
    return 0;
}
