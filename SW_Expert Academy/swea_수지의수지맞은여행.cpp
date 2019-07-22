#include <iostream>
using namespace std;

int T;
char map[22][22];
int R, C;
bool visit[30];
int _max;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int y, int x, int cnt) {

	visit[map[y][x] - 'A'] = 1;//�ѹ� �� �� ���� �ʱ� ���� �� �� check

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > C || ny > R)
			continue;
		if (!visit[map[ny][nx] - 'A']) { //�� �� �Ⱥ�����, cnt �ø��� ���� ĭ����.
			dfs(ny, nx, cnt + 1);
		}
	}
	visit[map[y][x] - 'A'] = 0;//�� �̻� �������� ��θ� ���� ��ǥ �ٽ� 0����
	if (_max < cnt) _max = cnt;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> R >> C;
		for (int y = 1; y <= R; y++) {
			for (int x = 1; x <= C; x++) {
				cin >> map[y][x];
			}
		}
		dfs(1, 1, 1);
		cout << '#' << test_case << ' ' << _max << '\n';
		_max = 0;
	}

}