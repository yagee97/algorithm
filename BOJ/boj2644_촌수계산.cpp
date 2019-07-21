#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, start, finish;
vector<int> relation[102];
int dist[102];
int bfs()
{
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == finish)
			return dist[x];
		for (int i = 0; i < relation[x].size(); i++) {
			int y = relation[x][i];
			if (dist[y])
				continue;
			q.push(y);
			dist[y] = dist[x] + 1; //경로구하는거 잊지말기
		}
	}
	return -1;
}
int main()
{
	cin >> n >> start >> finish >> m;
	for (int r = 0; r < m; r++)
	{
		int x, y;
		cin >> x >> y;
		relation[x].push_back(y);
		relation[y].push_back(x);
	}

	cout << bfs();


}