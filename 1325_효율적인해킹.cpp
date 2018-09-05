#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a, b;
int check[10001];
int dp[10001];
vector<int> v[10001];

int dfs(int i, int j)
{
	if (check[i] == j)
		return 0;
	int result = 0;
	result++;
	check[i] = j;

	for (auto it : v[i])
		result += dfs(it, j);

	return result;

}

int main(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dfs(i, i);
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
		if (max < dp[i])
			max = dp[i];
	for (int i = 1; i <= n; i++)
		if (max == dp[i])
			printf("%d ", i);

}