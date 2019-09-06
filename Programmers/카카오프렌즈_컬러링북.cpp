#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
void bfs(int m, int n, vector<vector<int>> picture, int x, int y);
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int ans = 0;
int c[101][101] = { 0, };

struct pos {
	int x, y;
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int idx = 0;
	int cnt = 0;
	ans = 0;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	memset(c, 0, sizeof(c));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!c[i][j] && picture[i][j] != 0) {
				bfs(m, n, picture, i, j);
				idx++;
			}
 		}
	}

	number_of_area = idx;
	max_size_of_one_area = ans;
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	printf("%d %d", answer[0], answer[1]);
	return answer;
}

void bfs(int m, int n, vector<vector<int>> picture, int x, int y)
{
	int cnt = 1;
	queue<pos> q;
	q.push({ x,y });
	c[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= m || ny >= n || nx < 0 || ny < 0)
				continue;
			if (!c[nx][ny] && picture[x][y] == picture[nx][ny]) {
				q.push({ nx,ny });
				c[nx][ny] = true;
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
}
