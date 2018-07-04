#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<cstdlib>
using namespace std;

int n;
char s[1010];
bool vis_1[100],vis_2[100];

int main() {
    while(cin>>n&&n) {
        scanf("%s",s);
        int l=strlen(s);
        memset(vis_1,0,sizeof vis_1);
        memset(vis_2,0,sizeof vis_2);
        int num=0;
        int ans=0;
        for(int i=0; i<l; i++) {
            if(num<n) {
                if(!vis_1[s[i]-64])
                    num++,vis_1[s[i]-64]=1;
                else
                    num--,vis_1[s[i]-64]=0;
            } else {
                if(vis_1[s[i]-64]) {
                    num--;
                    vis_1[s[i]-64]=0;
                } else if(!vis_2[s[i]-64]) {
                    ans++;
                    vis_2[s[i]-64]=1;
                }
            }
        }
        if(ans)
            printf("%d customer(s) walked away. ",ans);
        else
            printf("All customers tanned successfully. ");
    }
}
