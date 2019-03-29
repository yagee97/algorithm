#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int n, m,num;
int map[102][102] = { 0, };
int dx[4] = { -1,0,1,0 },dy[4] = { 0,1,0,-1 };

void bfs(int startX, int startY)
{
	queue<pair<int,int>> q;
	q.push(make_pair(startX,startY));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny <0 || nx > n-1 || ny > m-1)
				continue;
			if (map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				 map[nx][ny] = map[x][y] + 1;
				//지금까지의 경로개수에 한개 추가해서 다음까지 가는거 계산
			}
		}
	}

}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		scanf("%1d", &map[i][j]);
		}
	}

	bfs(0,0);
	cout << map[n-1][m-1];
}