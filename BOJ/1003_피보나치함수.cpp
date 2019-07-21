#include <cstdio>
#include <iostream>
using namespace std;

int t,n,dp[41];

int fibonacci(int n)
{
	if (n <= 0) {
		dp[0] = 0;
		return 0;
	}
	else if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	if (dp[n]==-1) {
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return dp[n];
	}
	else {
		return dp[n];
	}
}

int main(void)
{
	int result;

	fill_n(dp, 41, -1);
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		if (n == 0) {
			printf("1 0\n");
		}
		else if (n == 1) {
			printf("0 1\n");
		}
		else {
			fibonacci(n);
			printf("%d %d\n", dp[n - 1], dp[n]);
		}
	}


}