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
bool selected[11] = {0,};//���̷��� �̹� �����. �ߺ�Ȯ��
int c[60][60] = {0,};
int d[60][60] = { 0, };//�Ÿ�, �ð�
int times = 0, result = 999999;

//�� �۶߷ȳ� Ȯ��
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
	//������ virus. queue�� �ְ� �湮ó��
	for (int i = 0; i < (int)select_virus.size(); i++) {
		int x = select_virus[i].x;
		int y = select_virus[i].y;
		q.push({ x,y });
		c[x][y] = true;
	}

	while (!q.empty()) {
		int size = q.size();
		//���ÿ�, ���������� bfs�� ����Ǿ�� �ϸ�!
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
				//2�ΰ��� ���� �ǳ�? �׷���. ���þ��� ���̷��� �� ���� �����ϱ�!
				if (!c[nx][ny] && map[nx][ny] != 1) {
					c[nx][ny] = true;
					d[nx][ny] = d[x][y] + 1; //�Ÿ����
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

//m�� ����
void dfs(int cnt, int idx)
{
	if (cnt == m)
	{
		memset(c, false, sizeof(c));
		memset(d, 0, sizeof(d));
		//���̷��� ���ÿ� �۶߸���
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