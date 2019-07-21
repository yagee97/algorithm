#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
int t, m, n,k;
int cnt;
int map[52][52];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int c[52][52];
void dfs(int x, int y) {

	c[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (!c[nx][ny] && map[nx][ny] == 1) {
			dfs(nx, ny);
			c[nx][ny] = true;
		}
	}
}
int main()
{
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <n; j++) {
				map[i][j] = 0;
				c[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && !c[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}

}