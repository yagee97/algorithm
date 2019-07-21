#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n,cnt1 = 0, cnt2=0;
char map[102][102];
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int c[102][102] = {false, };

void bfs1(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	c[x][y] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > n || ny > n)
				continue;
			if (!c[nx][ny] && map[x][y] == map[nx][ny]) {
				q.push(make_pair(nx, ny));
				c[nx][ny] = true;
			}
		}
	}

}

void bfs2(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	c[x][y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > n || ny > n)
				continue;
			//Àû³ì»ö¾à
			if (map[x][y] == 'R' || map[x][y] == 'G') {
				if (!c[nx][ny] && (map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
					q.push(make_pair(nx, ny));
					c[nx][ny] = true;
				}
			}
			else {
				if (!c[nx][ny] && map[nx][ny] == 'B') {
					q.push(make_pair(nx, ny));
					c[nx][ny] = true;
				}
			}
		}
	}

}

int main()
{

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cnt1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!c[i][j]) {
				bfs1(i, j);
				cnt1++;
			}
		}
	}

	memset(c, false, sizeof(c));

	cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!c[i][j]) {
				bfs2(i, j);
				cnt2++;
			}
		}
	}
	cout << cnt1 << ' ' <<cnt2;
}