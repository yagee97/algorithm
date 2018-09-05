#include <cstdio>
#include <algorithm>

using namespace std;

int n,Max=0;
int box[1001];
int dp[1001];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &box[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = 1; //상자에 최소 1개는 넣을 수 있어서!
		for (int j = 1; j <= i;j++)
		{
			if (box[i] > box[j])//뒤에 상자가 더 커야댐
				dp[i] = max(dp[i], dp[j] + 1);
		}
		Max = max(Max, dp[i]);//최대길이
	}
	printf("%d", Max);

	return 0;
}