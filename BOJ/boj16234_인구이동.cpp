#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N, L, R;
int map[52][52], c[52][52], moving[52][52];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int cnt = 0, sum = 0, result= 0;
bool cal(int a, int b)
{
	int res;
	res = abs(a - b);
	if (res >= L && res <= R)
		return true;
	else
		return false;
}

int dfs(int y, int x)
{
	c[y][x] = true;
	int sum = map[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx >= N || nx < 0)
			continue;
		if (cal(map[y][x], map[ny][nx]) == false)
			continue;
		if (!c[ny][nx] && cal(map[y][x], map[ny][nx])) {
			cnt++;
			moving[ny][nx] = true;
			sum += dfs(ny,nx);
		}
	}
	return sum;
}

void move(int population)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (moving[i][j])
			{
				map[i][j] = population;
				moving[i][j] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	while (1)
	{
		bool flag = false;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!c[i][j]) {
					cnt = 1;
					int s = dfs(i, j);
					int population = s / cnt;
					if (cnt > 1) { // 연합이 일어났으면
						map[i][j] = population;
						move(population);//인구이동
						flag = true;
					}
				}
			}
		}

		if (flag) result++;
		else break; //인구이동 안일어났으면 break
	}
	cout << result;

}