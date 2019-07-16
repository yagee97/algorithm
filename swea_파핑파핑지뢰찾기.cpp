#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
char map[302][302];
int count_map[302][302];//Áö·Ú°³¼ö ÀúÀå¸Ê
int c[302][302];
int n,t;
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1, 0, 1, 1,1,0,-1,-1 };
int result = 0;

struct pos {
	int x, y;
};

void check()
{
	int cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			if (map[i][j] == '*')
			{
				count_map[i][j] = -1;
				continue;
			}
			for (int k = 0; k < 8; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (map[ni][nj] == '*') {
					cnt++;
				}
			}
			count_map[i][j] = cnt;
		}

	}
}

void bfs(int x, int y)
{
	queue<pos> q;
	q.push({ x,y });
	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		c[nx][ny] = true;
		for (int i = 0; i < 8; i++) {
			int new_x = nx + dx[i];
			int new_y = ny + dy[i];
			if (new_x < 0 || new_y <0 || new_x >= n || new_y >= n) {
				continue;
			}
			if (!c[new_x][new_y]) {
				c[new_x][new_y] = true;
				if (count_map[new_x][new_y] == 0) {
					q.push({ new_x, new_y });
				}
			}
		}
		q.pop();
	}
}

int main()
{
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n;
		result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		check();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (count_map[i][j] == 0 && !c[i][j]) {
					bfs(i, j);
					result++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (count_map[i][j] > 0 && !c[i][j]) {
					result++;
				}
			}
		}
		cout << "#" << test << " " << result << endl;
		memset(c, 0, sizeof(c));
	}
}