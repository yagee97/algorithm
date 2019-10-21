#include <iostream>
#include <cmath>

using namespace std;
int N, L, ans;
int map[105][105], c[105][105];

void slope(int i, bool c)
{
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		int d;
		if (c == 1) {
			d = map[i][j + 1] - map[i][j];
		}
		else if (c == 0) {
			d = map[j + 1][i] - map[j][i];
		}
		if (d == 0) { //���� ĭ�̶� ����ĭ�� ������
			cnt++;
		}
		else if (d == 1 && cnt >= L)//���̰� 1�ε� ���ӵ� ĭ��
			//���� ���̸�ŭ �ִٸ�. ���� ���� �ٽ� cnt =1
			cnt = 1;
		else if (d == -1 && cnt >= 0)
			//���̰� -1. �� ����ĭ���� ���� ��ĭ�� ���϶�
			//������ ���̰� ���� ĭ�� -L+1��ŭ �־����. �׷���
			//cnt�� 0���� Ŀ���� ĭ�� �ִ°�. 
			cnt = -L + 1;
		else
			return; //���� ������. �� return;
	}
	if (cnt >= 0)
		ans += 1;
}

void solve()
{
	//��� �� �����ؼ� �� ����
	for (int i = 0; i < N; i++) {
		slope(i, 1);
		slope(i, 0);
	}
	cout << ans << "\n";
}

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();

}