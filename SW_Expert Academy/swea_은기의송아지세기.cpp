#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
int T, N, Q;
int cow[100001];
int cnt[100001][4];
int one, two, three;
int main()
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &Q);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &cow[i]);
		}

		one = 0;
		two = 0;
		three = 0;

		for (int i = 1; i <= N; i++) {
			if (cow[i] == 1) {
				one++;
			}
			else if (cow[i] == 2) {
				two++;
			}
			else if (cow[i] == 3) {
				three++;
			}

			cnt[i][1] = one;
			cnt[i][2] = two;
			cnt[i][3] = three;
		}

		printf("%#d\n", test_case);
		for (int i = 1; i <= Q; i++) {
			int L, R;
			scanf("%d %d", &L, &R);

			printf("%d %d %d\n", cnt[R][1] - cnt[L - 1][1], 
				cnt[R][2] - cnt[L-1][2], cnt[R][3] - cnt[L-1][3]);
		}
		memset(cow, 0, sizeof(cow));
		memset(cnt, 0, sizeof(cnt));
	}
}
