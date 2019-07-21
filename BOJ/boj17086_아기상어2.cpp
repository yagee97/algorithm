#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n, m, map[55][55];
queue<pair<int, int>> shark;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int c[55][55] = {false, },result = -1;

/* 상어가 있는 곳에서 각 빈칸 까지의 모든 거리를 구하고,
제일 최대가 되는 빈칸까지의 거리 찾기
*/

void bfs()
{
	while (!shark.empty()) {
		int x = shark.front().first;
		int y = shark.front().second;
		shark.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] == 0 && !c[nx][ny]) {
				c[nx][ny] = true;
				shark.push(make_pair(nx, ny));
				map[nx][ny] = map[x][y] + 1;
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
			if (map[i][j] == 1) {
				shark.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > result)
				result = map[i][j];
		}
	}

	cout << result - 1;

}