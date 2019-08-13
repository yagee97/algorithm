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
				diff[i - 1] = map[i] - map[i - 1];//두 집 사이의 거리 구하기
			}
		}
		sum = 0;
		sort(diff, diff + N -1);
		for (int i = 0; i < N - K; i++) {
			sum += diff[i]; //차이가 적은 곳들 더 하기. N개의 집 중에 k개의 발전소를 설치하고 남은곳.
		}
		printf("#%d %lld\n", test_case, sum);
	}
}