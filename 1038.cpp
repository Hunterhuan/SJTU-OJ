#include <iostream>

using namespace std;
int monkey[10005];
int M;

int search(int k,int start)
{
    int count = 0;
    while(count<k)
    {
        if(start > M )
            start = 1;
        if(monkey[start] ==0 )
        {
            ++count;
            if(count==k)
            {
                monkey[start] = 1;
                return ++start;
            }
        }
        ++start;
    }
}
int main()
{
    cin>>M;
    int begin = 1;
    for(int i=0;i<M-1;++i)
    {
        int tmp;
        cin>>tmp;
        tmp = tmp%(M-i);
        if(tmp==0)
            tmp = M-i;
        begin = search(tmp,begin);
    }
    for(int i=1;i<=M;++i)
    {
        if(monkey[i]==0)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}



// 约瑟夫环就应该这么解
// 直接推导出来答案。这个是逆向的思路
// 本来是一个一个删，这个从1个慢慢加
#include <iostream>
using namespace std;
int K[10000]={0};
int main()
{
    int M;
    cin>>M;
    int ans=0;
    for(int i=1;i<=M-1;i++){
        cin>>K[i];
    }
    for(int i=2;i<=M;i++)
    {
        ans = (ans+K[M-i+1]) % i;
    }    
    cout<<ans+1<<endl;
    return 0;
}