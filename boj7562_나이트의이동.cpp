#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int I, t;
struct pos {
	int x, y;
};
int check[305][305] = { false, };

pos start;
pos dest;
int dx[] = { -1,1,2,2,1,-1,-2,-2 };
int dy[] = { 2,2,1,-1,-2,-2,-1,1 };

void bfs(int r, int c)
{
	queue<pos> q;
	q.push({ r,c });
	check[r][c] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x == dest.x && y == dest.y)
			break;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= I || ny >= I)
				continue;
			if (!check[nx][ny]) {
				check[nx][ny] = check[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

}

int main()
{
	cin >> t;

	while (t--) {
		cin >> I;
		memset(check, 0, sizeof(check));
		int sx, sy;
		cin >> sx >> sy;
		int dex, dey;
		cin >> dex >> dey;

		start = { sx, sy };
		dest = { dex, dey };

		bfs(start.x, start.y);
		cout << check[dest.x][dest.y] - 1 << endl;
	}

}