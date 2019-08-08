#include <queue>
#include <utility>
#include <stdio.h>
using namespace std;
int map[102][102];
int dx[4] = { -1, 0, 1,  0 };
int dy[4] = { 0, 1, 0, -1 };
int d[102][102];
int N;
void bfs()
{
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= N || ny >= N || nx < 0 || ny < 0)
				continue;
			if (d[nx][ny] > d[x][y] + map[nx][ny]) {
				d[nx][ny] = d[x][y] + map[nx][ny]; //최소값으로 갱신
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
				d[i][j] = 9999999;
			}
		}
		d[0][0] = 0;//시작은 0으로
		bfs();
		printf("%#d %d\n", test_case, d[N - 1][N - 1]);
		
	}
}