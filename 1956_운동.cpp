#include <cstdio>

using namespace std;
void calculate_cost();

int v, e;
int d[401][401];
int a, b, cost,result = 10001;

int main(void)
{
	scanf("%d%d", &v, &e);

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			d[i][j] = 10001;
		}
	}

	for (int i = 1; i <= e; i++)
	{
			scanf("%d%d%d", &a, &b, &cost);
			d[a][b] = cost;	
	}

	calculate_cost();

	for (int i = 1; i <= v; i++)
	{
		if (result > d[i][i])
			result = d[i][i];
	}

	if (result == 10001)
		printf("-1");
	else
	printf("%d", result);

}

void calculate_cost()
{
	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}