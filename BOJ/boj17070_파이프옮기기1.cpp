#include <iostream>

using namespace std;
int n;
int map[16][16];

typedef struct {
	int x;
	int y;
}Dir;

int cnt = 0;
Dir d[3] = { {0,1},{1,0},{1,1} };

void dfs(int x, int y, int dir)
{
	if (x == n - 1 && y == n - 1)
	{
		cnt++;
		return;
	}
	// i는 나아갈 방향, dir은 현재 방향
	for (int i = 0; i < 3; i++) {
		if ((dir == 0 && i == 1) || (dir == 1 && i == 0))
			continue;
		int nx = x + d[i].x;
		int ny = y + d[i].y;
		if (map[nx][ny] == 1 || nx >= n || ny >= n)
			continue;
		//대각선
		if (i == 2 && (map[x + 1][y] == 1 || map[x][y + 1] == 1))
			continue;
		dfs(nx, ny, i);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 1, 0);
	cout << cnt << "\n";
}