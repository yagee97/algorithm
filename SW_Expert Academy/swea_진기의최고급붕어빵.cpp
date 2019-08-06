#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, max_time;
	int N, M, K;
	bool flag;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int num[11111] = { 0 };
		flag = true;
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			num[tmp] += 1; //몇초에 몇명의 손님이 오는지 카운트
		}
		int cnt = 0;
		//max_time = *max_element(num, num + N);

		for (int i = 0; i < 11111; i++) {

			if (N == 0) break; //손님다끝났으면

			if (i != 0 && i%M == 0) {
				cnt += K;
			}
			if (num[i] == 0)//그 초에 손님 안오면
				continue;

			else if (num[i] > 0 && cnt >= num[i]) {//붕어빵 개수가 그 초의 사람 수보다 많으면
				cnt -= num[i];//붕어빵 사람 수 만큼 나눠주고
				N -= num[i];//사람 제거
			}
			else flag = false;
		}

		if (flag) {
			cout << "#" << test_case << " " << "Possible\n";
		}
		else {
			cout << "#" << test_case << " " << "Impossible\n";
		}
	}
	return 0;
}