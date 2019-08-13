#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;

int T,N,K;
ll map[100001];
ll diff[100001];
ll sum =0;

int main(void)
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &map[i]);
			if (i != 0) {
				diff[i - 1] = map[i] - map[i - 1];//�� �� ������ �Ÿ� ���ϱ�
			}
		}
		sum = 0;
		sort(diff, diff + N -1);
		for (int i = 0; i < N - K; i++) {
			sum += diff[i]; //���̰� ���� ���� �� �ϱ�. N���� �� �߿� k���� �����Ҹ� ��ġ�ϰ� ������.
		}
		printf("#%d %lld\n", test_case, sum);
	}
}