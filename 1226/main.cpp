#include <iostream>

using namespace std;
int num[10000000];
template<class T>
void quickSort(T s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r;
        T x = s[l];
        while (i < j)
        {
            while(i < j && !(s[j]< x)) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}
int count(int num[], int sum){
    int res = 1;
    if(sum<=1)
        return sum;
    for(int i=1;i<sum;++i){
        if(num[i]!=num[i-1])
            ++res;
    }
    return res;
}
int main()
{
    int sum;
    cin>>sum;
    for(int i=0;i<sum;++i){
        cin>>num[i];
    }
    quickSort(num, 0, sum-1);
    for(int i=0;i<sum;++i){
        cout<<num[i]<<' ';
    }
    //cout<<count(num,sum);
    //cout << "Hello world!" << endl;
    return 0;
}
