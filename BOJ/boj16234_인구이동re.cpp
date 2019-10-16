#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int N, L, R;
int A[101][101];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1, 0};
int c[101][101] = { 0, };
int people_cnt, country;
int result = 0;
bool flag = false;

struct info {
	int x;
	int y;
};

vector<info> Union_country;

void dfs(int x, int y)
{

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= N || ny >= N || nx < 0 || ny < 0)
			continue;

		int diff = abs(A[x][y] - A[nx][ny]);

		if (L <= diff && R >= diff && !c[nx][ny]) {
			people_cnt += A[nx][ny];
			country++;
			c[nx][ny] = true;
			Union_country.push_back({ nx,ny });
			dfs(nx, ny);
		}
	}
}

void move_start()
{
	for (int i = 0; i < Union_country.size(); i++)
	{
		int x = Union_country[i].x;
		int y = Union_country[i].y;

		A[x][y] = people_cnt / country;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	while (1) {
		flag = false;
		memset(c, false, sizeof(c));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!c[i][j]) {
					c[i][j] = true;
					people_cnt = A[i][j];
					country = 1;
					Union_country.clear();
					Union_country.push_back({ i,j });

					dfs(i, j);//연합하고
					if (country == 1)
						continue;

					flag = true;
					move_start();
					
				}
			}
		}
		if (flag == false)
			break;
		result++;
	}

	cout << result;
}