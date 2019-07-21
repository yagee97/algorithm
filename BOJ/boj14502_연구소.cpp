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
				q.push(make_pair(i, j));//바이러스 좌표 저장
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
			if (virus[nx][ny] == 0) { //인접한 곳에 바이러스 퍼뜨리기
				virus[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0) { //바이러스 다 퍼졌는데도 0인곳
				res += 1; //안전영역
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
				copyM[i][j] = 1; //벽세우기
				make_wall(cnt + 1); //한개 세우고 한개 더세움
				copyM[i][j] = 0; //벽 3개 세우고 나서 다시 0만들기
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
				copyM[i][j] = 1; //시작하는 점에 벽세움
				make_wall(1);
				copyM[i][j] = 0;
			}
		}
	}
	cout << max_value;
}