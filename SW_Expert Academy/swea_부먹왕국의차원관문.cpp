#include <stdio.h>

using namespace std;

int T, N, D;
int map[300002];
int result = 0, cursor = 0;

void solution()
{
	for (int i = 1; i <= N; i++) {
		cursor++;
		if (map[i] == 1) {
			cursor = 0;
			continue;
		}
		if (cursor == D) {
			if (map[i] == 0) {
				cursor = 0;
				map[i] = 1;
				result++;
			}
		}
	}
}

int main(void)
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d", &N, &D);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &map[i]);
		}

		solution();
		printf("#%d %d\n", test_case, result);
		result = 0;
	}
}