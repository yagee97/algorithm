#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int map[10][10];
int new_map[10][10];

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int ans = 987654321;
int cctv_cnt;

struct info {
	int x;
	int y;
	int dir;//0~3
	int num;//1~6
};
vector<info> cctv;

void copy_map(int map[10][10], int new_map[10][10])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_map[i][j] = map[i][j];
		}
	}
}

void right(int x, int y)
{
	for (int i = y; i < m; i++)
	{
		if (new_map[x][i] == 6)
			break;
		if (new_map[x][i] == 0)
			new_map[x][i] = -1;
	}
}

void down(int x, int y)
{
	for (int i = x; i < n; i++)
	{
		if (new_map[i][y] == 6)
			break;
		if (new_map[i][y] == 0)
			new_map[i][y] = -1;
	}
}

void left(int x, int y)
{
	for (int i = y; i >= 0; i--)
	{
		if (new_map[x][i] == 6)
			break;
		if (new_map[x][i] == 0)
			new_map[x][i] = -1;
	}
}

void up(int x, int y)
{
	for (int i = x; i >= 0; i--)
	{
		if (new_map[i][y] == 6)
			break;
		if (new_map[i][y] == 0)
			new_map[i][y] = -1;
	}
}

void solve(vector<info> cctv)
{
	copy_map(map, new_map);
	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].x;
		int y = cctv[i].y;
		int dir = cctv[i].dir;
		int number = cctv[i].num;

		//한방향으로 쭉
		if (number == 1) {
			if (dir == 0) {
				right(x, y);
			}
			else if (dir == 1) {
				down(x, y);
			}
			else if (dir == 2) {
				left(x, y);
			}
			else if (dir == 3) {
				up(x, y);
			}
		}
		else if (number == 2) {
			if (dir == 0 || dir == 2) {
				right(x, y);
				left(x, y);
			}
			else if (dir == 1 || dir == 3) {
				up(x, y);
				down(x, y);
			}
		}
		else if (number == 3) {
			if (dir == 0) {
				right(x, y);
				down(x, y);
			}
			else if (dir == 1) {
				down(x, y);
				left(x, y);
			}
			else if (dir == 2) {
				left(x, y);
				up(x, y);
			}
			else if (dir == 3) {
				up(x, y);
				right(x, y);
			}
		}
		//세방향
		else if (number == 4) {
			if (dir == 0) {
				left(x, y);
				up(x, y);
				right(x, y);
			}
			else if (dir == 1) {
				up(x, y);
				right(x, y);
				down(x, y);
			}
			else if (dir == 2) {
				right(x, y);
				down(x, y);
				left(x, y);
			}
			else if (dir == 3) {
				down(x, y);
				left(x, y);
				up(x, y);
			}
		}
		else if (number == 5) {
			right(x, y);
			down(x, y);
			left(x, y);
			up(x, y);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_map[i][j] == 0)//사각지대
				cnt++; 
		}
	}
	ans = min(ans, cnt);
}

void dfs(int idx, vector<info> cctv) {

	if (idx == cctv_cnt) {
		solve(cctv);
		return;
	}

	cctv[idx].dir = 0;
	dfs(idx + 1, cctv);
	cctv[idx].dir = 1;
	dfs(idx + 1, cctv);
	cctv[idx].dir = 2;
	dfs(idx + 1, cctv);
	cctv[idx].dir = 3;
	dfs(idx + 1, cctv);


}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >=1 && map[i][j] <=5)
			{
				cctv.push_back({ i,j,0,map[i][j] });
			}
		}
	}

	cctv_cnt = (int)cctv.size();

	dfs(0, cctv);

	cout << ans;
}