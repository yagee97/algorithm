#include <cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, m;
int input[501][501];

int dp[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int x, int y)
{
	if (dp[x][y] != -1) 
		return dp[x][y]; 
	//값이 존재
	if (x < 0 || x >= n || y < 0 || y >= m) 
		return 0; //범위를 벗어난 경우
	if (x == 0 && y == 0) 
		return 1;

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i]; 

		if (input[nx][ny] > input[x][y])
			dp[x][y] += dfs(nx, ny);
	}

	return dp[x][y];
}

int main(void)
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &input[i][j]);

	memset(dp, -1, sizeof(dp));

	printf("%d", dfs(n - 1, m - 1));

}