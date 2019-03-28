#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> a[1001];
int visit[1001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!visit[y])
			{
				visit[y] = true;
				q.push(y);
			}
		}
	}
}

void dfs(int start)
{
	if (visit[start])
		return;
	visit[start] = true;
	cout << start << ' ';
	for (int i = 0; i < a[start].size(); i++)
	{
		int y = a[start][i];
		dfs(y);
	}

}

int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	
	dfs(v);
	memset(visit, false, sizeof(visit));
	cout << endl;
	bfs(v);

}