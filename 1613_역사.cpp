#include <cstdio>
using namespace std;

int n, k, s;
bool know[401][401];
int check[401][401];

int main()
{
	scanf("%d%d", &n, &k);
	while (k--) {
		int happen1, happen2;
		scanf("%d%d", &happen1, &happen2);
		know[happen1][happen2] = true;
		know[happen2][happen1] = false;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (know[i][k] && know[k][j])
					know[i][j] = true;
			}
		}
	}
	scanf("%d", &s);
	for (int cnt = 0; cnt < s; cnt++)
	{
		int hap1, hap2;
		scanf("%d%d", &hap1, &hap2);
		if (!know[hap1][hap2] && !know[hap2][hap1])
			printf("0\n");
		else if (know[hap1][hap2])
			printf("-1\n");
		else if (!know[hap1][hap2])
			printf("1\n");

	}

}