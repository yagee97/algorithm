#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<vector<int>> graph;
int c[102], result=0;

struct temp {
	int node;
	int time;
};

int bfs(int x)
{
	int lastTime = -1;
	int lastNode = -1;

	queue<temp> q;
	q.push({ x, 0 });
	c[x] = true;

	while (!q.empty())
	{
		int x = q.front().node;
		int time = q.front().time;
		q.pop();

		//제일 마지막에 연락받는애 찾아야함.
		if (lastTime < time) {
			lastTime = time;
			lastNode = x;
		}
		//마지막에 연락받은애가 여러명이면 제일 큰 애
		else if (lastTime == time && lastNode < x) {
			lastNode = x;
		}

		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i];
			if (!c[nx]) {
				c[nx] = true;
				q.push({ nx, lastTime + 1 });
			}
		}
	}
	return lastNode;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int length, start_node;
		cin >> length >> start_node;
		graph.resize(length);
		for (int i = 0; i < length/2; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			graph[tmp1].push_back(tmp2);
		}

		result = bfs(start_node);
		cout <<"#" << test_case << " " << result << "\n";
		memset(c, 0, sizeof(c));
		graph.clear();
	}
} 