#include <stdio.h>

using namespace std;

int main()
{
	int N, M, sum[100002];
	scanf("%d %d", &N, &M);
	sum[0] = 0;
	int map[100002];
	for (int i = 1; i <= N; i++) {
		scanf("%d", &map[i]);
		sum[i] = sum[i-1] + map[i];
	}
	for (int i = 1; i <= M; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		printf("%d\n", sum[num2] - sum[num1 - 1]);
	}
}