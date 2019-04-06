#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, t=0,a[133][133], d[133][133];
int c[133][133] = {0,};

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	
	bool operator <(const Edge &edge) const{
		return edge.distance < this->distance;
	}
};
int main()
{
	while (1) {
		t++;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				d[i][j] = INF;
			}
		}
		d[0][0] = a[0][0];//Ã³À½ node
		priority_queue<Edge> pq;
		pq.push({ 0, 0, 0 });
		while (!pq.empty())
		{
			Edge curEdge = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = curEdge.node[0] + dx[i];
				int ny = curEdge.node[1] + dy[i];
				//if (nx <= 0 || ny <= 0 || nx > n || ny > n)
				//	continue;
				if (d[nx][ny] > d[curEdge.node[0]][curEdge.node[1]] + a[nx][ny]) {
					d[nx][ny] = d[curEdge.node[0]][curEdge.node[1]] + a[nx][ny];
					pq.push({ nx,ny,d[nx][ny] });
				}
			}
		}
		cout << "Problem " << t << ": " << d[n - 1][n - 1] << '\n';
	}
}