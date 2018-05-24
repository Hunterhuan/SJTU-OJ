#include <iostream>

using namespace std;

int count1(int num)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(num & flag)
            count++;
        flag = flag<<1;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int sum = 0;
    int tmp;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        sum += count1(tmp);
    }
    cout << sum << endl;
    return 0;
}
