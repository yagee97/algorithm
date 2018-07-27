#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, s, num;
int cow[201], home[201];
bool visit[201];
vector<int> adj[201];
int result = 0;

bool dfs(int v)
{
	int next;
	if (visit[v] == true)
		return false;
	visit[v] = true;

	for (int i = 0; i < adj[v].size(); i++)
	{
		next = adj[v][i];

		if (home[next] == -1 || dfs(home[next])) {
			cow[v] = next;
			home[next] = v;
			return true;
		}
	}
	return false; //실패
}

int main(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s);
		for (int j = 0; j < s; j++) {
			scanf("%d", &num);
			adj[i].push_back(num);
		}
	}

	for (int i = 1; i <= n; i++)
		cow[i] = -1; //-1로 초기화
	for (int i = 1; i <= m; i++)
		home[i] = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			visit[j] = false;
		}
		if (dfs(i)) result++;
	}

	printf("%d", result);


}