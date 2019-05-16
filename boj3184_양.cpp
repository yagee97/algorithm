#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

int R, C;
char map[255][255];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int c[255][255] = { false, };
int wolfN=0, sheepN=0;
int total[2] = {0,0};

void bfs(int x,int y)
{
	queue<pos> q;
	q.push({ x,y });
	c[x][y] = true;

	sheepN = 0;
	wolfN = 0;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (map[x][y] == 'o')
			sheepN++;
		if (map[x][y] == 'v')
			wolfN++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (c[nx][ny] || map[nx][ny] == '#')
				continue;

			c[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	if (sheepN > wolfN)
		total[0] += sheepN;
	else
		total[1] += wolfN;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!c[i][j] && map[i][j] != '#') {
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		cout << total[i] << ' ';
	}
	
	
}