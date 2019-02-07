#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, cnt;
int iceberg[301][301];
int temp[301][301];
int checked[301][301];

int melting(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx < 0 || mx >= n || my < 0 || my >= m)
			continue;
		if (iceberg[mx][my] == 0) {
			cnt++;
		}
	}
	return cnt;
}

void dfs(int x, int y, int ret) {
	checked[x][y]++;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (checked[nx][ny] == ret && iceberg[nx][ny] > 0) {
			dfs(nx, ny, ret);
		}
	}
}

int component_num(int ret) {
	int comp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (checked[i][j] == ret && iceberg[i][j] > 0) {
				comp++;
				dfs(i, j, ret);
			}
		}
	}
	return comp;
}

int main(void)
{
	scanf("%d%d", &n, &m);
	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &iceberg[i][j]);
		}
	}

	memset(temp, 0, sizeof(temp));

	int tmp = 0;
	while ((tmp = component_num(result)) < 2) {
		if (tmp == 0) {
			result = 0;
			break;
		}
		result++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (iceberg[i][j] > 0) {
					temp[i][j] = melting(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (iceberg[i][j] > 0) {
					iceberg[i][j] = max(iceberg[i][j] - temp[i][j], 0);
				}
			}
		}
	}
	printf("%d", result);
}