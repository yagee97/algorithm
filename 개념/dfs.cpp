#include <iostream>
#include <vector>

using namespace std;

int num = 7;
int c[8];
vector<int> a[8];

void dfs(int x)
{
	if (c[x]) return;
	c[x] = true; //처음방문이면 방문처리
	cout << x << ' ';

	for (int i = 0; i < a[x].size(); i++) //인접노드
	{
		int y = a[x][i];
		dfs(y);//인접노드 대상으로 dfs수행.
	}
}

int main(void) {

	a[1].push_back(2);
	a[2].push_back(1); //서로 연결되어 있다는 것을 표현. 간선

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(8);

	dfs(1);
	return 0;
}