#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll  N, M;
ll jewel[300001];
ll result = 1000000000;
ll Max;

int main(void) {

	scanf("%lld%lld", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld", &jewel[i]);
		Max = max(Max, jewel[i]);
	}

	ll left = 1, right = Max;//구간을 1부터 보석최대갯수로

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < M; i++)
		{
			sum += jewel[i] / mid;
			if (jewel[i] % mid != 0)
				sum++;
		}

		if (sum <= N) {//보석갯수가 학생수보다 적으면
			right = mid - 1;
			if (mid < result)
				result = mid;
		}
		else//보석갯수가 학생수보다 많이 남으면 
			left = mid + 1;
	}

	printf("%lld\n", result);

}