#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int n, m, k, cnt;
int visit[101][101] = {0,};
vector<int> a;

int dfs(int x, int y)
{
	int area;
	area = 1;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (!visit[nx][ny])
			area = area + dfs(nx, ny);
	}
	return area;
}

int main()
{
	cin >> m >> n >>k;

	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				visit[y][x] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j]) {
				a.push_back(dfs(i, j));
			}
		}
	}

	sort(a.begin(), a.end());
	cout << a.size() << endl;

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';

}