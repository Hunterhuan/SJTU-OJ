# include <stdio.h>

# define INF 105

int n, x, tmp;

int curSum, minSum;
int ans;

int Min(int x, int y) {return x<y ? x:y;}
int Max(int x, int y) {return x>y ? x:y;}

int main()
{
    scanf("%d", &n);
    minSum = INF;
    curSum = 0;
    ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        curSum += x;
        ans = Max(ans, curSum-minSum);
        minSum = Min(minSum, curSum-x);
        tmp = x;
    }

    if (ans > 0) printf("%d\n", ans);
    else printf("Game Over\n");

    return 0;
}
