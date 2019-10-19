#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321
using namespace std;
int n, m;
int map[55][55];
bool selected[13*13];
int sum = 0;
int ans = MAX;

struct pos {
	int x;
	int y;
};

vector<pos> chicken;
vector<pos> home;
vector<pos> tmp;

int dist_cal(int x, int y, int x2, int y2)
{
	int dist = abs(x - x2) + abs(y - y2);
	return dist;
}

void solve()
{
	sum = 0;
	for (int i = 0; i < (int)home.size(); i++)
	{
		int chicken_dist = MAX;
		for (int j = 0; j < (int)tmp.size(); j++)
		{
			int d = dist_cal(home[i].x, home[i].y, tmp[j].x, tmp[j].y);
			if (chicken_dist > d)
				chicken_dist = d;
		}
		sum += chicken_dist;
	}
}

void dfs(int cnt, int idx)
{
	if (cnt == m)
	{
		solve();
		//최소값 찾기
		if (ans > sum)
			ans = sum;
		return;
	}
	for (int i = idx; i < chicken.size(); i++)
	{
		if (!selected[i])
		{
			selected[i] = true;
			tmp.push_back(chicken[i]);
			dfs(cnt + 1, i);
			selected[i] = false;
			tmp.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back({ i,j });
			if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << ans;
}