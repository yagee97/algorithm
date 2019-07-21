#include <cstdio>

using namespace std;

int t,n,m;
int a, b;

int main(void)
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m;i++)
			scanf("%d%d", &a, &b);
		printf("%d\n", n - 1);
	}
}