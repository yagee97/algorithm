#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[8][8];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int MAX = 0;

typedef struct {
	int x;
	int y;
}pos;
vector<pos> virus;

void mapcopy(int map[8][8], int new_map[8][8])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_map[i][j] = map[i][j];
		}
	}
}

void spread()
{
	int virus[8][8];
	queue<pos> q;
	mapcopy(map, virus);
	//virus 위치 queue에
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= m || nx < 0 || ny < 0)
				continue;
			if (virus[nx][ny] == 0) {
				virus[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0) {
				ans++;
			}
		}
	}
	//최대 안전영역
	if (MAX < ans) {
		MAX = ans;
	}
}

void dfs(int cnt)
{
	//벽 3개 세우면 spread()
	if (cnt == 3) {
		spread();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;//벽세우기
				dfs(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0);
	cout << MAX << "\n";
}