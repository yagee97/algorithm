#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		return parent[b] = a;
	else
		return parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	else
		return 0;
}


class Edge {
public:
	int node[2];
	int cost;

	Edge(int a, int b, int cost) {
		this->node[0] = a;
		this->node[1] = b;
		this->cost = cost;
	}

	bool operator <(Edge &edge) {
		return this->cost < edge.cost;
	}
};

int main()
{
	vector<Edge> v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}

	sort(v.begin(), v.end());

	int parent[100002];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int last = 0;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//사이클이 발생하지 않는 경우 그래프에 포함
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			last = v[i].cost;
			sum += v[i].cost;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum - last << endl;
}