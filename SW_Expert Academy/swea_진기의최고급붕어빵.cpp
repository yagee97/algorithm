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
			num[tmp] += 1; //���ʿ� ����� �մ��� ������ ī��Ʈ
		}
		int cnt = 0;
		//max_time = *max_element(num, num + N);

		for (int i = 0; i < 11111; i++) {

			if (N == 0) break; //�մԴٳ�������

			if (i != 0 && i%M == 0) {
				cnt += K;
			}
			if (num[i] == 0)//�� �ʿ� �մ� �ȿ���
				continue;

			else if (num[i] > 0 && cnt >= num[i]) {//�ؾ ������ �� ���� ��� ������ ������
				cnt -= num[i];//�ؾ ��� �� ��ŭ �����ְ�
				N -= num[i];//��� ����
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