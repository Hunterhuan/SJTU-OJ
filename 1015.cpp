#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[4000];
    char b[4000];
    cin>>a>>b;

    int end1 ,end2;
    for(int i=0;i<4000;++i)
        if(a[i]=='\0')
        {
            end1 = i;
            break;
        }
    for(int i=0;i<4000;++i)
        if(b[i]=='\0')
        {
            end2 = i;
            break;
        }
    int n1[4000],n2[4000],result[4000];
    // 转换成int
    for(int i=1;i<=end1;++i)
        n1[i] = int(a[end1-i] -'0');
    for(int i=1;i<=end2;++i)
        n2[i] = int(b[end2-i] -'0');

    for(int i=1;i<=end1;++i)
    {
        for(int j=1;j<=end2;++j)
        {
            result[i+j-1] += n1[i]*n2[j];
            result[i+j] +=  result[i+j-1]/10;
            result[i+j-1] = result[i+j-1]%10;
        }
    }
    // 找到长度
    int len = end1+end2;
    while(result[len]==0 && len>1)
        --len;
    for(int j=len;j>0;--j)
        cout<<result[j];
    return 0;
}
