#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

//�ο���http://www.hankcs.com/program/cpp/poj-1742-coins.html

int dp[100000 + 16];
int A[100 + 16];
int C[100 + 16];
int main()
{
	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (dp[j] >= 0)
				{
					dp[j] = C[i];
				}
				else if (j < A[i]						// ��һ���ͳ�����������
						|| dp[j - A[i]] <= 0)		// ���ձ�jС������ʱ�������ˣ���ʱ����������
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - A[i]] - 1;		// ������һ����i��Ӳ��
				}
			}
		}
		int answer = count_if(dp + 1, dp + 1 + m , bind2nd(greater_equal<int>(), 0)); // �ܶ�0�����ڴ���
		cout << answer << endl;
	}
    return 0;
}






#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

bool value[100016];
int A[102];
int C[102];

int main(){
    int n,m;
    while(true){
        cin>>n>>m;
        if(m==0 && n==0)
            return 0;
        memset(value, 0, sizeof(value));
        memset(A, 0, sizeof(A));
        memset(C, 0, sizeof(C));
        for(int i=0;i<n;++i)
            scanf("%d", &A[i]);
        for(int i=0;i<n;++i)
            scanf("%d", &C[i]);
        value[0] = true;
        for(int i=0;i<n;++i){
            for(int k=m;k>=0;--k){
                if(value[k]){
                    for(int j=1;j<=C[i];++j){
                        if(k+A[i]*j<=m){
                            value[k+A[i]*j] = true;
                            //cout<<k<<" is true "<<A[i]<<' '<<k+A[i] <<" is true"<<endl;
                        }
                        else
                            break;
                    }
                }
            }
        }
        int res = 0;
        for(int i=1;i<=m;++i){
            if(value[i])
                ++res;
        }
        cout<<res<<endl;
    }
    return 1;
}
