#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int nums[4] = {0};
	for(int i=0;i<s.size();++i){
		if(s[i]=='S'){
			nums[0]++;
		}
		else if(s[i]=='T'){
			nums[1]++;
		}
		else if(s[i]=='A'){
			nums[2]++;
		}
		else if(s[i]=='R'){
			nums[3]++;
		}
	}
	cout<<nums[0]*nums[1]*nums[2]*nums[3]<<' ';
	int res = min(nums[0], min(nums[1], min(nums[2], nums[3])));
	cout<<res<<' ';

	int cnt = 0;
	int cnt_tmp = 4;
	vector<int> v(s.size(), false);
    for(int i=0;i<res;++i){
        cnt_tmp = 4;
        for(int j=0;j<s.size();++j){
            if(s[j]=='S' && !visited[j]){
                if(cnt_tmp==4){
                    cnt_tmp--;
                    visited[j] = true;
                }
            }else if(s[j]=='T' && !visited[j]){
                if(cnt_tmp==3){
                    cnt_tmp--;
                    visited[j] = true;
                }
            }else if(s[j]=='A' && !visited[j]){
                if(cnt_tmp==2){
                    cnt_tmp--;
                    visited[j] = true;
                }
            }else if(s[j]=='R' && !visited[j]){
                if(cnt_tmp==1){
                    cnt_tmp--;
                    visited[j] = true;
                    ++cnt;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
