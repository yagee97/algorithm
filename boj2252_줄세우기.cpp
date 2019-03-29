#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> a[32001];
int inDegree[32001];

void topologySort()
{
	int result[32001];
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty())
			return;
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		a[p1].push_back(p2);
		inDegree[p2]++;
	}
	
	topologySort();

}