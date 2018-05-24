#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int operation[55][3];
double price[10005][2];
int m,n;
double stock = 0,money1 = 0,money2 = 0;
void readdata()
{
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>operation[i][0]>>operation[i][1]>>operation[i][2];
    }
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>price[i][0]>>price[i][1];
    }
}
int find_price(int t)
{
    int begin=0,end = n-1;
    while(begin<=end){
        int mid = (begin+end)/2;
        if(price[mid][0]>t)
            end = mid-1;
        else
            begin = mid+1;
    }
    return price[end][1];
}
void operate()
{
    for(int i=0;i<m;++i)
    {
        int t=operation[i][0],a=operation[i][1],d=operation[i][2];
        if(d==1){
            double current_price = find_price(t);
            stock += a;
            double money = a*100*current_price;
            double money_1 = max(money*0.002,5.0);
            double money_2 = a/10.0;
            money1 += money+money_1+money_2+1.0;
        }
        if(d==2){
            double current_price = find_price(t);
            stock -= a;
            double money = a*100*current_price;
            double money_1 = max(money*0.002,5.0);
            double money_2 = a/10.0;
            double money_3 = money*0.001;
            money2 += money-money_1-money_2-1.0-money_3;
        }
    }
}

int main()
{
    readdata();
    operate();
    printf("%.2f",money2-money1);
    return 0;
}
