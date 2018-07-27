#include <cstdio>
#include <vector>
using namespace std;

vector<int> employee[1001];
bool visit[1001];
int work[1001];

int n, m;
int cnt, num;
int i, j;
int result = 0;

int dfs(int p)
{
	int i, w;

	if (visit[p])    
		return 0;
	visit[p] = true;

	for (i = 0; i < employee[p].size(); i++) {
		w = employee[p][i];

		if (!work[w] || dfs(work[w])) {
			work[w] = p;
			return 1;
		}
	}
	return 0;
}

int main()
{

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		scanf("%d", &cnt);

		while (cnt--) {
			scanf("%d", &num);
			employee[i].push_back(num);
		}

		for (j = 1; j <= n; j++)   
			visit[j] = false;

		//if (dfs(i)) result++;
		result += dfs(i);
	}

	printf("%d\n", result);

	return 0;
}