#include <cstdio>
#include <algorithm>

#define INF 500001

using namespace std;
typedef long long ll;

ll n, m;
ll num1[500001],num2[500001];
ll result[500001];

int bs(int k)
{
	int left = 0, right = n;

	while (left <= right)
	{
		int mid = (left + right) / 2;

			if (k > num1[mid])
				left = mid + 1;
			else if (k < num1[mid])
				right = mid - 1;
			else
				return 1;
	}
	return 0;
}

int main(void)
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &num1[i]);

	scanf("%lld", &m);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &num2[i]);

	sort(num1, num1 + n+1);

	for (int i = 1; i <= m; i++)
		printf("%d ", bs(num2[i]));

}