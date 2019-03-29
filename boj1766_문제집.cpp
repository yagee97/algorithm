#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<int> a[32001];
int inDegree[32001];

void topologySort()
{
	// Ǯ�� ���� �������� Ǯ��� �ؼ�, ���� ���ں��� �켱����
	priority_queue<int, vector<int>,greater<int>> q;
	int result[32001];
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty())
			return;
		int x = q.top();
		q.pop();
		result[i] = x;
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];//����� ����
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
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		inDegree[y]++;
	}

	topologySort();

}