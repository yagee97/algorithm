#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[17][17];
int c[17][17];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int flag = 0, cnt;

struct Pos {
	int x, y;
};
Pos start;

void bfs(int x, int y)
{
	queue<Pos> q;
	q.push({ x,y});
	c[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (map[x][y] == '3')
		{
			flag = 1;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
	
			if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16) {
				continue;
			}
			if (map[nx][ny] == '1') {
				continue;
			}
			if (map[nx][ny] != '1' && !c[nx][ny]) {
				q.push({ nx,ny });
				c[nx][ny] = true;
			}
		}

	}
}
int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		memset(c, 0, sizeof(c));
		cin >> cnt;
		for (int i = 0; i < 16; i++)
		{
			flag = 0;
			for (int j = 0; j < 16; j++) {
				cin >> map[i][j];

				if (map[i][j] == '2') {
					start.x = i;
					start.y = j;
				}
			}
		}

		bfs(start.x, start.y);
		cout << "#" << test_case << " " << flag << endl;

	}
}