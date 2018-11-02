#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, k;
int visited[10001];
int b[10001];
int x, y;
vector<vector<int>> node;

int dfs(int here)
{
	if (visited[here] == 1)//방문된 정점 매칭불가
		return 0;
	visited[here] = 1;
	for (int i = 0; i < node[here].size(); i++)
	{
		int there = node[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	return 0;
}

int bmatch() {
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (dfs(i))ret++;
	}
	return ret;
}

int main(void)
{
	scanf("%d%d", &n,&k);
	node.resize(n + 1);
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &x, &y);
		node[x].push_back(y);
	}
	printf("%d\n", bmatch());
	return 0;

}
