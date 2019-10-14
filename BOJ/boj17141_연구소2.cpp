#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, map[60][60];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
struct pos {
	int x;
	int y;
};
vector<pos> virus;
vector<pos> select_virus;
bool selected[11] = {0,};//바이러스 이미 골랐나. 중복확인
int c[60][60] = {0,};
int d[60][60] = { 0, };//거리, 시간
int times = 0, result = 999999;

//다 퍼뜨렸나 확인
bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1) continue;
			if (c[i][j] == false) return false;
		}
	}
	return true;
}

void spread()
{
	queue<pos> q;
	//선택한 virus. queue에 넣고 방문처리
	for (int i = 0; i < (int)select_virus.size(); i++) {
		int x = select_virus[i].x;
		int y = select_virus[i].y;
		q.push({ x,y });
		c[x][y] = true;
	}

	while (!q.empty()) {
		int size = q.size();
		//동시에, 병렬적으로 bfs가 실행되어야 하면!
		for (int qs = 0; qs < size; qs++)
		{
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			times = d[x][y];
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= n || ny >= n || nx < 0 || ny < 0)
					continue; 
				//2인곳도 가도 되나? 그러네. 선택안한 바이러스 일 수도 있으니까!
				if (!c[nx][ny] && map[nx][ny] != 1) {
					c[nx][ny] = true;
					d[nx][ny] = d[x][y] + 1; //거리계산
					q.push({ nx,ny });
				}
			}
		}
	}
	if (check()) {
		if (result > times)
			result = times;
	}
}

//m개 선택
void dfs(int cnt, int idx)
{
	if (cnt == m)
	{
		memset(c, false, sizeof(c));
		memset(d, 0, sizeof(d));
		//바이러스 동시에 퍼뜨리기
		spread();
		return;
	}
	for (int i = idx; i < (int)virus.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			select_virus.push_back(virus[i]);
			dfs(cnt + 1, i);
			select_virus.pop_back();
			selected[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	dfs(0, 0);
	if (result == 999999)
		cout << "-1";
	else
		cout << result;

}