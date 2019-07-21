#include <cstdio>
#include <algorithm>
using namespace std;

int n,dp[1001][5];

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &dp[i][1],&dp[i][2], &dp[i][3]);

			dp[i][1] += min(dp[i - 1][2], dp[i - 1][3]);
			dp[i][2] += min(dp[i - 1][1], dp[i - 1][3]);
			dp[i][3] += min(dp[i - 1][1], dp[i - 1][2]);
	}
	printf("%d", min(dp[n][1], min(dp[n][2], dp[n][3])));

}