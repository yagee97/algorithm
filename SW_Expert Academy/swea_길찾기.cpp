#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> map;
int c[101], flag = 0;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c[start] = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == 99) {
			flag = 1;
			break;
		}
		for (int i = 0; i < map[x].size(); i++) {
			int y = map[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = 1;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int test_case = 1; test_case <= 10; test_case++) {
		int t, num;
		cin >> t >> num;
		map.resize(num);
		for (int k = 0; k < num; k++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			map[temp1].push_back(temp2);
		}
		bfs(0);
		cout << "#" << test_case << ' ' << flag << endl;
		flag = 0;
		memset(c, 0, sizeof(c));
		map.clear();
	}
}