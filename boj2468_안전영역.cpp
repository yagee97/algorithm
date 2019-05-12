#include <iostream>
#include <cstring>
using namespace std;
int n, map[101][101];
int high = 0, result = 0;
int c[101][101] = {false, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y, int cnt)
{
	if (cnt > high)
		return;
	c[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (!c[nx][ny] && map[nx][ny] > cnt) {
			c[nx][ny] = true;
			dfs(nx, ny, cnt);
		}
	}

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (high < map[i][j]) {
				high = map[i][j];
			}
		}
	}
	
	while (high--) {
		memset(c, false, sizeof(c));
		int ret = 0;
		for (int i = 0; i < n; i++) {	
			for (int j = 0; j < n; j++) {
				if (!c[i][j] && map[i][j] > high) {
					dfs(i, j, high);
					ret++;
				}
			}
			
		}
		if (result < ret)
			result = ret;
	}
	cout << result;

}