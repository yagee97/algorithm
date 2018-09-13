#include <cstdio>
using namespace std;
int dp[31][31];

int main()
{
	int T, N, M;

	scanf("%d", &T);

	dp[0][0] = 1;

	for (int i = 1; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			if (i != 1) {
				for (int k = j - 1; k >= 1; k--)
					dp[i][j] = dp[i][j] + dp[i - 1][k];
			}
			else
				dp[i][j] = j;
		}
	}

	for (int i = 0; i < T; i++) {
		scanf("%d%d", &N, &M);
		printf("%d\n", dp[N][M]);
	}

	return 0;
}