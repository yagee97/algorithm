#include <cstdio>
#include <algorithm>

using namespace std;
int people[4][2];
int result[4];
int Maxx=0;

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &people[i][j]);
	}
	result[0] = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 2; j++)
		{
			result[i] = result[i - 1] + (people[i][j] - people[i][j - 1]);
			Maxx = max(result[i], Maxx);
		}
	}

	printf("%d", Maxx);
}