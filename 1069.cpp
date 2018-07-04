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
