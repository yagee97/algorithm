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
		ll a[2]; // �� 2�� �Է� ����
		cin >> a[0] >> a[1];

		ll total[2] = { 0 }; // ���� 4�� �� 0������ ���� ���� �����

		for (int j = 0; j < 2; j++) {    // �� ������ ���� ���
			ll temp; // ����� �ٲپ� ����
			if (a[j] > 0)
				temp = a[j];
			else
				temp = -a[j];

			vector<int> vec;  // �� �ڸ��� ������ ���� ���Ϳ� ����
			while (temp != 0) {
				vec.push_back(temp % 10);
				temp /= 10;
			}

			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] >= 4) // 4 �̻��� ��� 1 �����Ͽ� 9������ ����(4�� ���� 9�� �̹Ƿ� 9���̴�)
					vec[i]--;
				total[j] += (vec[i] * pow(9, i));
			}
		}

		if (a[0] > 0 && a[1] > 0) // �Ѵ� ����� �������
			answer = total[1] - total[0];
		else if (a[0] < 0 && a[1] > 0)    // �ڿ��� ����� ���ϰ� 1�� ������ (0���� �����Ƿ�)
			answer = total[1] + total[0] - 1;
		else if (a[0] < 0 && a[1] < 0)    // �Ѵ� ������ ���ְ� ������ ���������
			answer = total[0] - total[1];

		printf("#%d %lld\n", testcase, answer);
	}
	return 0;
}