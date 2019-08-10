#include <stdio.h>

using namespace std;

int N, map[49][49];
int T;

int solution()
{
	int sum = 0;
	int size = N / 2;
	for (int i = 0; i < size; i++)//위쪽 삼각형
	{
		for (int j = size - i; j <= size + i; j++) {
			sum += map[i][j];
		}
	}
	for (int i = size; i >= 0; i--) //가운데 포함 아래쪽 삼각형
	{
		for (int j = size - i; j <= size + i; j++) {
			sum += map[N - 1 - i][j];
		}
	}
	return sum;
}

int main()
{
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		printf("#%d %d\n", test_case, solution());
	}
}