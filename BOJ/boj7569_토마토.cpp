#include <cstdio>
#include <queue>
using namespace std;

struct tomato {
	int x, y, z;
};

int m, n, h, ans;
int map[101][101][101];
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
queue<tomato> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) 
				continue; 
			if (!map[nx][ny][nz]) {
				map[nx][ny][nz] = map[x][y][z] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &m, &n, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}

				if (ans < map[i][j][k]) ans = map[i][j][k];
			}
		}
	}
	printf("%d\n", ans - 1);
	return 0;
}