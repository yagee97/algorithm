#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, cnt = 0;
vector<int> a[1001];
int visit[1001] = { false, };

int main()
{

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			visit[i] = true;
			q.push(i);
			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				for (int j = 0; j < a[x].size(); j++) {
					int y = a[x][j];
					if (!visit[y])
					{
						visit[y] = true;
						q.push(y);
					}
				}
			}
		}
	}
	cout << cnt;

}