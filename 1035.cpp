

//  堆排序，并不会，mark，看代码看不懂



//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//bool comp(pair<int,int> a,pair<int,int> b)
//{
//    if(a.second>b.second)
//        return true;
//    else if(a.second==b.second)
//    {
//        if(a.first<b.first)
//            return true;
//        return false;
//    }
//    else
//        return false;
//}
//
//int main()
//{
//    int N,price;
//    cin>>N;
//    pair<int,int> stocks[20005];
//    for(int i=0;i<N;++i)
//    {
//        cin>>price;
//       stocks[i].first = i+1;
//       stocks[i].second = price;
//    }
//    int K,r;
//    char q;
//    cin>>K;
//    for(int i=0;i<K;++i)
//    {
//        cin>>q;
//        if(q=='Q')
//        {
//            cin>>r;
//            sort(stocks,stocks+N,comp);
//            for(int j=0;j<r;++j)
//            {
//                int tmp;
//                cin>>tmp;
//                cout<<stocks[tmp-1].first<<' ';
//            }
//            cout<<endl;
//        }
//        if(q=='M')
//        {
//            int tmp;
//            cin>>tmp;
//            for(int k=0;k<N;++k)
//            {
//                if(stocks[k].first==tmp)
//                {
//                    cin>>tmp;
//                    stocks[k].second = tmp;
//                    break;
//                }
//            }
//        }
//    }
//    return 0;
//}




#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void MAX_HEAPIFY(int A[], int data[], int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = -1;
    if(l<n && data[A[l]]>data[A[i]]){
        largest = l;
    }else if(l<n && data[A[l]] == data[A[i]]){
        if(A[l]<A[i])
            largest = l;
        else
            largest = i;
    }else{
        largest = i;
    }
    if(r<n && data[A[r]]>data[A[largest]])
        largest = r;
    else if(r<n && data[A[r]]==data[A[largest]]){
        if(A[r]<A[largest])
            largest = r;
    }
    if(largest!=i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MAX_HEAPIFY(A, data, n, largest);
    }
}

void BUILD_MAX_HEAP(int A[], int data[], int n){
    for(int i = n/2-1;i>=0;i--)
        MAX_HEAPIFY(A,data,n,i);
}

void HEAPSORT(int query[], int data[], int n, int r){
    int A[n];
    for(int i = 0;i<n;i++)
        A[i] = i;
    BUILD_MAX_HEAP(A,data,n);

    int x = *max_element(query,query+r);
    int res[x];
    for(int i=0;i<x;i++){
        res[i] = A[0];
        n--;
        A[0] = A[n];
        MAX_HEAPIFY(A,data,n,0);
    }
    for(int y = 0; y<r; y++){
        cout<<res[query[y]-1]+1<<" ";
    }
    cout<<endl;
}
int main() {
    int n;
    cin>>n;
    int stock[n];
    for(int i=0;i<n;i++){
        scanf("%d",&stock[i]);
    }
    int k;
    cin>>k;
    while(k-->0){
        char op;
        cin>>op;
        if(op=='Q'){
            int r;
            cin>>r;
            int query[r];
            for(int i = 0;i<r;i++){
                int temp;
                cin>>temp;
                query[i]=temp;
            }
            HEAPSORT(query,stock,n,r);
        }
        else{
            int a,b;
            cin>>a>>b;
            stock[a-1] = b;
        }
    }
    return 0;
}
