#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct info {
	int x;
	int y;
};

int T, N, M, R, C, L;
int map[55][55];
int c[55][55] = { 0, };
int cnt = 0;
int dx[4] = { 0,0,1,-1 }, dy[4] = { -1,1,0,0 }; // ¼­ µ¿ ³² ºÏ

void bfs()
{
	queue<info> q;
	q.push({ R , C });
	c[R][C] = true;

	while (--L) {

		int s = q.size();

		while (s--)
		{
			int x = q.front().x;
			int y = q.front().y;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				bool f = false;

				if (nx >= N || ny >= M || nx < 0 || ny < 0)
					continue;

				int a = map[x][y];
				int b = map[nx][ny];

				if (!c[nx][ny]) {
					if (a == 1)
					{
						if (i == 0 && (b == 1 || b == 3 || b == 4 || b == 5))
							f = true;
						else if (i == 1 && (b == 1 || b == 3 || b == 6 || b == 7))
							f = true;
						else if (i == 2 && (b == 1 || b == 2 || b == 4 || b == 7))
							f = true;
						else if (i == 3 && (b == 1 || b == 2 || b == 5 || b == 6))
							f = true;
					}
					else if (a == 2)
					{
						if (i == 2 && (b == 1 || b == 2 || b == 4 || b == 7))
							f = true;
						else if (i == 3 && (b == 1 || b == 2 || b == 5 || b == 6))
							f = true;
					}
					else if (a == 3)
					{
						if (i == 0 && (b == 1 || b == 3 || b == 4 || b == 5))
							f = true;
						else if (i == 1 && (b == 1 || b == 3 || b == 6 || b == 7))
							f = true;
					}
					else if (a == 4)
					{
						if (i == 1 && (b == 1 || b == 3 || b == 6 || b == 7))
							f = true;
						else if (i == 3 && (b == 1 || b == 2 || b == 5 || b == 6))
							f = true;
					}
					else if (a == 5)
					{
						if (i == 1 && (b == 1 || b == 3 || b == 6 || b == 7))
							f = true;
						else if (i == 2 && (b == 1 || b == 2 || b == 4 || b == 7))
							f = true;
					}
					else if (a == 6)
					{
						if (i == 0 && (b == 1 || b == 3 || b == 4 || b == 5))
							f = true;
						else if (i == 2 && (b == 1 || b == 2 || b == 4 || b == 7))
							f = true;
					}
					else if (a == 7)
					{
						if (i == 0 && (b == 1 || b == 3 || b == 4 || b == 5))
							f = true;
						else if (i == 3 && (b == 1 || b == 2 || b == 5 || b == 6))
							f = true;
					}
					if (f) {
						c[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {

		cin >> N >> M >> R >> C >> L;
		cnt = 0;
		memset(c, false, sizeof(c));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}

		bfs();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (c[i][j])
					cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
}