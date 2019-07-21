#include <iostream>
#include <cstring>

using namespace std;
int t, n;
int map[102][102], tmp[102][102];
int c[102][102] = { false, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
int result = 0, s = 0;

void dfs(int x, int y)
{
	c[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (map[nx][ny] != 0 && c[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		s++;
		result = 0;
		memset(map, 0, sizeof(map));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		//0일일때도 봐줘야한다.
		for (int k = 0; k <= 100; k++) {
			memset(c, 0, sizeof(c));
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (k == map[i][j]) { // 요정이 먹음
						map[i][j] = 0;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] != 0 && c[i][j] == 0) {
						dfs(i, j);
						cnt++; // dfs가 돌때마다 덩어리 한개씩 추가
					}
				}
			}
			if (result < cnt)
				result = cnt;
		}
		cout << "#" << s << " " << result << endl;
	}
}