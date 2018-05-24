#include <iostream>
#include <cstring>
using namespace std;


int ans[15]={0};//用来存储结果

void add(unsigned long long x){
    int i = 0;//从个位开始
    while(x){
        ans[i] += (x % 10);//加上最初的x的当前位的那个数
        //因为当前位是最低位(个位) 所以直接%10就可以了
        ans[i] %= 10;
        i++;//计算高一位的
        x /= 10;//处理左一位
    }
}
//计算从l加到r的superXOR
void superXOR(unsigned long long l, unsigned long long r){
    //将ans初始为0
    memset(ans,0,sizeof(ans));
    for (unsigned long long i = l; i <= r; ++i)
        add(i);//向ans中叠加

    //输出时要反着输出,这时候要找第一个最高位
    int high=14;//假设high是14
    for (; high>=0; --high) if(ans[high]!=0)//不是0
        break;
    if(high == -1)//说明全是0
        cout<<0;
    else
        for (int i = high; i >=0 ; --i)
            cout<<ans[i];
    cout<<endl;
}

inline bool judge(unsigned long long x){
    return x%100==99;
}

int main(int argc, char const *argv[])
{
    int N; cin>>N;
    for (int i = 0; i < N; ++i)
    {
        unsigned long long x; cin>>x;
        if(x<99)
            superXOR(1,x);
        else{
            unsigned long long tmp = x;
            while(!judge(tmp))
                tmp--;
            superXOR(tmp+1,x);
        }
    }
    return 0;
}
