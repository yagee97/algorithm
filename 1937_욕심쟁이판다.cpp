#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int dfs(int i, int j) {

	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = 1;

	if (j > 0 && arr[i][j] < arr[i][j - 1]) { // 왼쪽
		dp[i][j] = max(dp[i][j], 1 + dfs(i, j - 1));
	}
	if (j < n - 1 && arr[i][j] < arr[i][j + 1]) { // 오른쪽
		dp[i][j] = max(dp[i][j], 1 + dfs(i, j + 1));
	}
	if (i > 0 && arr[i][j] < arr[i - 1][j]) { // 위
		dp[i][j] = max(dp[i][j], 1 + dfs(i - 1, j));
	}
	if (i < n - 1 && arr[i][j] < arr[i + 1][j]) { // 아래
		dp[i][j] = max(dp[i][j], 1 + dfs(i + 1, j));
	}

	return dp[i][j];
}

int main() {
	int i, j;
	int result = -1;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (dp[j][i] == -1) {
				dfs(j, i);
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result = max(result, dp[i][j]);
		}
	}
	printf("%d", result);
}