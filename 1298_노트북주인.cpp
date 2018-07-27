#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, nb[101];
bool check[101];
vector<int> adj[101];
int result = 0;

bool dfs(int v) {
	int next;

	if (check[v]) 
		return false;
	check[v] = true;

	for (int i = 0; i < adj[v].size(); i++)
	{
		next = adj[v][i];

		if (!nb[next] || dfs(nb[next]))
		{
			nb[next] = v;
			return true;
		}
	}
	return false;
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			check[j] = false;
		}
		if (dfs(i)) 
			result++;
	}
	printf("%d", result);

}