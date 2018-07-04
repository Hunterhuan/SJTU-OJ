#include <iostream>
#include <cmath>
using namespace std;

int K,n,ans = 1;
int a[3000005],q1[3000005],q2[3000005];
void solve()
{
    int l1=1,l2=1,r1=0,r2=0,t=1;
    for(int i=0;i<=n;++i){
        while(l1<=r1&&a[i]>=a[q1[r1]])
            r1--;
        while(l2<=r2&&a[i]<=a[q2[r2]])
            r2--;
        q1[++r1] = i;
        q2[++r2] = i;
        while(a[q1[l1]]-a[q2[l2]]>K)
            if(q1[l1]<q2[l2]){
                    t=q1[l1]+1;
                    l1++;}
            else
                t=q2[l2]+1,l2++;
        ans = max(ans,i-t+1);
    }
}

int main()
{
    cin>>K>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    solve();
    cout<<ans;
    return 0;
}


//long long seq[3000005];
//long long k;
//int n;
//int main()
//{
//    cin>>k>>n;
//    for(int i=0;i<n;++i){
//        cin>>seq[i];
//    }
//    int large_index = 0;
//    int little_index = 0;
//    int longest = 0;
//
//    int begin = 0,end = 1;
//    while(begin<n && end<n){
//        if(seq[end]>=seq[large_index]){
//            large_index = end;
//        }
//        else if(seq[end]<=seq[little_index]){
//            little_index = end;
//        }
//        else
//        {
//            if(end-begin+1 >longest)
//                longest = end-begin+1;
//            ++end;
//            continue;
//        }
//        if(seq[large_index]-seq[little_index]>k)
//        {
//            if(little_index==end)
//                begin = large_index+1;
//            else if(end==large_index)
//                begin = little_index+1;
//            end = begin+1;
//            large_index = begin;
//            little_index = begin;
//        }
//        else
//            ++end;
//    }
//    cout<<longest;
//    return 0;
//}


