#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, c[101] = {0,};
vector<int> v[101];
int cnt = 0;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	c[x] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(1);

	cout << cnt;
}