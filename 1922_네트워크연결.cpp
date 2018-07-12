#include <cstdio>

using namespace std;

int n, m, a,b,c;
int d[1001];
int g[1001][1001];
int result = 0;
bool checked[1001] = {false, };

int prim()
{
	int min, index, sum = 0;

	for (int i = 1; i <= n; i++)
	{
		d[i] = g[1][i]; //1부터 시작하게 정점 잡은거.
	}

	checked[1] = true;

	for (int j = 1; j < n; j++)
	{
		min = 99999999;
		for (int i = 1; i <= n; i++)
		{
			if (!checked[i] && d[i] < min) {
				min = d[i];
				index = i;
			}
		}

		sum = sum + min;
		checked[index] = true;//없던노드

		for (int i = 1; i <= n; i++)
		{
			if (d[i] > g[index][i])
				d[i] = g[index][i];
		}
	}
	return sum;
}

int main(void)
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			g[i][j] = 99999999;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = c;//방향이 없는 그래프!
	}

	result = prim();

	printf("%d", result);

}