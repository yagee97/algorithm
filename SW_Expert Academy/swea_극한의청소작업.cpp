#include <iostream>
#include <vector>
#include <math.h>

typedef long long int ll;

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		ll answer = 0;
		ll a[2]; // 층 2개 입력 받음
		cin >> a[0] >> a[1];

		ll total[2] = { 0 }; // 각각 4를 뺀 0층까지 층의 개수 저장용

		for (int j = 0; j < 2; j++) {    // 각 층마다 따로 계산
			ll temp; // 양수로 바꾸어 저장
			if (a[j] > 0)
				temp = a[j];
			else
				temp = -a[j];

			vector<int> vec;  // 각 자리수 마다의 값을 벡터에 저장
			while (temp != 0) {
				vec.push_back(temp % 10);
				temp /= 10;
			}

			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] >= 4) // 4 이상인 경우 1 감소하여 9승으로 저장(4를 빼면 9개 이므로 9승이다)
					vec[i]--;
				total[j] += (vec[i] * pow(9, i));
			}
		}

		if (a[0] > 0 && a[1] > 0) // 둘다 양수면 빼줘야함
			answer = total[1] - total[0];
		else if (a[0] < 0 && a[1] > 0)    // 뒤에가 양수면 더하고 1을 빼야함 (0층은 없으므로)
			answer = total[1] + total[0] - 1;
		else if (a[0] < 0 && a[1] < 0)    // 둘다 음수면 빼주고 음수를 취해줘야함
			answer = total[0] - total[1];

		printf("#%d %lld\n", testcase, answer);
	}
	return 0;
}