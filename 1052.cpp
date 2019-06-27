#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
//not done

void travel(set<int> s){
    for(auto t = s.begin(); t!=s.end();++t)
        printf("%d ", *t);
    printf("\n");
}

int main()
{
    int n;
    cin>>n;
    set<int> s[n];
    int nums[n];
    for(int i=0;i<n;++i){
        scanf("%d", &nums[i]);
    }
    int tmp;
    for(int i=0;i<n;++i){
        for(int j=0;j<nums[i];++j){
            scanf("%d", &tmp);
            s[i].insert(tmp);
        }
    }
    int m;
    cin>>m;
    char t;
    int a,b;
    for(int i=0;i<m;++i){
        cin>>t>>a>>b;
        if(t=='+'){
            set_union(s[a-1].begin(),s[a-1].end(),s[b-1].begin(),s[b-1].end(),inserter(s[a-1],s[a-1].begin()));
        }
        else if(t=='-'){
            set<int> newset;
            set_difference(s[a-1].begin(),s[a-1].end(),s[b-1].begin(),s[b-1].end(),inserter(newset,newset.begin()));
            s[a-1] = newset;
        }
        else if(t=='*'){
            set<int> newset;
            set_intersection(s[a-1].begin(),s[a-1].end(),s[b-1].begin(),s[b-1].end(),inserter(newset,newset.begin()));
            s[a-1] = newset;
        }
    }
    for(int i=0;i<n;++i){
        travel(s[i]);
    }
    return 0;
}
