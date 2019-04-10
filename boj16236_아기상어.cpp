#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;
int n, map[25][25];
int s_x, s_y, s_size = 2, s_eat = 0;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int f_dis[25][25], fish_cnt, result = 0;

class fish {
public:
	int x;
	int y;
	int d;
	fish(int a, int b, int dis) {
		this->x = a;
		this->y = b;
		this->d = dis;
	}
};

vector<fish> f;

bool cmp(const fish &a, const fish &b) {
	if (a.d == b.d) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
		}
	}
	else return a.d < b.d;
}
void bfs(int x, int y) {

	f_dis[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (f_dis[nx][ny] == 0 && map[nx][ny] <= s_size) {
				f_dis[nx][ny] = f_dis[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s_x = i;
				s_y = j;
				map[i][j] = 0;
			}
		}
	}
	while (1) {

		bfs(s_x, s_y);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > 0 && map[i][j] < s_size) {
					int dist = f_dis[i][j];
					if (dist > 0)
						f.push_back({ i,j,dist });
				}
					
			}
		}

		fish_cnt = (int)f.size();
		if (fish_cnt == 0)
			break;
		else if (fish_cnt > 1) {
			sort(f.begin(), f.end(), cmp);

			int nx = f[0].x;
			int ny = f[0].y;
			int time = f[0].d;

			s_eat++;
			if (s_eat == s_size) {
				s_eat = 0;
				s_size++;
			}
			s_x = nx;
			s_y = ny;
			map[s_x][s_y] = 0;
			f.clear();
			result += time;
			memset(f_dis, 0, sizeof(f_dis));
		}
	}

	cout << result;
}