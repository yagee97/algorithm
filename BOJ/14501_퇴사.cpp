#include <cstdio>

using namespace std;
int n;
int t, p;
int d[101];

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &t, &p);
		if (d[i] >= d[i + 1])
			d[i + 1] = d[i];

		if (d[i + t] <= d[i] + p)
			d[i + t] = d[i] + p;

	}
	printf("%d\n", d[n]);
}