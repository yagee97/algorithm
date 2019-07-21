#include <cstdio>
#include <cstring>

using namespace std;
int N;
int dp[1001][3][4];

int search(int o, int l, int a)
{
	if (l == 2 || a == 3)
		return 0;
	if (o == N)
		return 1;

	int &res = dp[o][l][a];

	if (res != -1)
		return res % 1000000;

	res = search(o + 1, l, 0) + search(o + 1, l + 1, 0) + search(o + 1, l, a + 1);

	return res % 1000000;

}
int main(void)
{
	scanf("%d", &N);
	memset(dp, -1, sizeof dp);
	printf("%d", search(0, 0, 0));

}