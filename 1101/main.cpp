#include <iostream>
#include <cstring>
using namespace std;


int ans[15]={0};//�����洢���

void add(unsigned long long x){
    int i = 0;//�Ӹ�λ��ʼ
    while(x){
        ans[i] += (x % 10);//���������x�ĵ�ǰλ���Ǹ���
        //��Ϊ��ǰλ�����λ(��λ) ����ֱ��%10�Ϳ�����
        ans[i] %= 10;
        i++;//�����һλ��
        x /= 10;//������һλ
    }
}
//�����l�ӵ�r��superXOR
void superXOR(unsigned long long l, unsigned long long r){
    //��ans��ʼΪ0
    memset(ans,0,sizeof(ans));
    for (unsigned long long i = l; i <= r; ++i)
        add(i);//��ans�е���

    //���ʱҪ�������,��ʱ��Ҫ�ҵ�һ�����λ
    int high=14;//����high��14
    for (; high>=0; --high) if(ans[high]!=0)//����0
        break;
    if(high == -1)//˵��ȫ��0
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
