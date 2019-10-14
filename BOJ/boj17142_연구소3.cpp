#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int n, m, map[55][55];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct pos {
	int x;
	int y;
};

vector<pos> virus;
bool selected[55 * 55];
int blank_cnt = 0;
int time = 0, result = 999999;
int d[55][55];

void spread()
{
	queue<pos> q;
	for (int i = 0; i < virus.size(); i++)
	{
		if (selected[i])
		{
			q.push({ virus[i].x, virus[i].y });
			d[virus[i].x][virus[i].y] = 0;//중요!
		}
	}

	int infect_cnt = 0, total = 0;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= n || ny >= n || nx < 0 || ny < 0 || map[nx][ny] == 1)
				continue;
			if (d[nx][ny] == -1)
			{
				if (map[nx][ny] == 2) {
					q.push({ nx,ny });
					d[nx][ny] = d[x][y] + 1;
				}
				if (map[nx][ny] == 0) {
					q.push({ nx,ny });
					d[nx][ny] = d[x][y] + 1;
					infect_cnt++;
					total = d[nx][ny];
				}
			}
		}
	}
	if (blank_cnt == infect_cnt && result > total) {
		result = total;
	}
}

void dfs(int cnt, int idx)
{
	if (cnt == m)
	{
		memset(d, -1, sizeof(d));
		//바이러스 퍼짐
		spread();
		return;
	}

	for (int i = idx; i < (int)virus.size(); i++)
	{
		if (!selected[i]) {
			selected[i] = true;
			dfs(cnt + 1, i);
			selected[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });
			if (map[i][j] == 0)
				blank_cnt++;
		}
	}
	dfs(0, 0);
	if (result == 999999)
		cout << "-1";
	else
		cout << result;
}