#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int p[10001];
int sum[10001];

int main(void)
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		sum[i] = p[i];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			sum[i] = max(sum[i], sum[i - j] + p[j]);
		}
	}

	printf("%d", sum[n]);
}