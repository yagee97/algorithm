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

	ll left = 1, right = Max;//������ 1���� �����ִ밹����

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < M; i++)
		{
			sum += jewel[i] / mid;
			if (jewel[i] % mid != 0)
				sum++;
		}

		if (sum <= N) {//���������� �л������� ������
			right = mid - 1;
			if (mid < result)
				result = mid;
		}
		else//���������� �л������� ���� ������ 
			left = mid + 1;
	}

	printf("%lld\n", result);

}