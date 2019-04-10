#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, map[27][27], cnt = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int c[27][27] = { 0, };
int result[27*27];

void dfs(int x, int y)
{
	result[cnt]++;
	c[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (!c[nx][ny] && map[nx][ny] != 0) {
			c[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!c[i][j] && map[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	sort(result, result + cnt);

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << endl;
	}


}