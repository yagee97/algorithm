#include <iostream>
#include <utility>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int n, m;
int map[15][15], copyM[15][15];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int max_value = 0;

void bfs()
{
	int virus[15][15];
	memcpy(virus, copyM, sizeof(copyM));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 2) {
				q.push(make_pair(i, j));//���̷��� ��ǥ ����
			}
		}
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (virus[nx][ny] == 0) { //������ ���� ���̷��� �۶߸���
				virus[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0) { //���̷��� �� �����µ��� 0�ΰ�
				res += 1; //��������
			}
		}
	}

	max_value = max(max_value, res);
}

void make_wall(int cnt)
{
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyM[i][j] == 0) {
				copyM[i][j] = 1; //�������
				make_wall(cnt + 1); //�Ѱ� ����� �Ѱ� ������
				copyM[i][j] = 0; //�� 3�� ����� ���� �ٽ� 0�����
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				memcpy(copyM, map, sizeof(map));
				copyM[i][j] = 1; //�����ϴ� ���� ������
				make_wall(1);
				copyM[i][j] = 0;
			}
		}
	}
	cout << max_value;
}