#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct arr{
    int r;
    int c;
    int v;
    bool operator < (const arr &a)const{
        return r<a.r;
    }
}array[100005];

int x[100005]; //记录下标 
int y[100005];
int n;

void Find(int a,int b){
    int xx = x[a],yy = y[b];
    bool flag = 0;
    for (int i = 0;i < n;++i){
        if (array[i].r == xx && array[i].c == yy) {
            printf("%d\n",array[i].v);
            flag = 1;
            break;
        }
    } 
    if (!flag) printf("%d\n",0);
}
int main(){
    int m;

    for (int i = 0;i < 100005;++i) x[i] = y[i] = i;
    scanf("%d",&n);
    for (int i =0;i < n;++i)
    {
        scanf("%d%d%d",&array[i].r,&array[i].c,&array[i].v);
    }
    // 关于 row 排序 一下
    sort(array,array+n); 


    // 妙，不直接交换，而是通过x, y去记录怎么变换的
    // 最后再统一转换。
    scanf("%d",&m);
    for (int i = 0;i < m;++i)
    {
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        switch (op){
            case 0:{
                if (a != b) {  
                    x[a] = x[a]^x[b]; //这就是坑爹的异或交换 ,只有下标不同才能换 
                    x[b] = x[a]^x[b];
                    x[a] = x[a]^x[b];
            }
                break;
            }
            case 1:{
                if (a != b) {
                    y[a] = y[a]^y[b];
                    y[b] = y[a]^y[b];
                    y[a] = y[a]^y[b];
                }
                break;
            }
            default:{
                Find(a,b);
            }
        }
    }
    return 0;
}