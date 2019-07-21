#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int dp[10001] = { 0, };
int wine[10001] = { 0, };

int maximum(int x, int y, int z)
{
	if (x > y)
		if (x > z)
			return x;
		else
			return z;
	else
		if (y > z)
			return y;
		else
			return z;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &wine[i]);
	}
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = maximum(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i], dp[i - 1]);
	}

	printf("%d", dp[n]);
}