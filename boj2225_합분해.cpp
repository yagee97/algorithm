#include <iostream>
using namespace std;

long long dp[201][201];

int main(void)
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			for (int s = 0; s <= j; s++) {
				dp[i][j] += dp[i - 1][j - s];
				dp[i][j] %= 1000000000;
			}

	cout << dp[k][n];

	return 0;

}