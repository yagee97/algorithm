#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, map[55][55], num = 0;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int c[55][55] = { 0, }, cnt[55*55];
int max_value = -1;
int mx = -1, sum =0;

int dfs(int x, int y, int num)
{
	int ret = 1;
	c[x][y] = num;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (c[nx][ny] || (map[x][y] & (1 << i)))
			continue;
		ret += dfs(nx, ny, num);
	}
	return ret;
}
int max2room(int x, int y) {

	int mx= 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int tmp = 0;
		if (c[nx][ny] != c[x][y]) {
			tmp = cnt[c[x][y]] + cnt[c[nx][ny]];
		}
		if (mx < tmp)
			mx = tmp;
	}
	return mx;
}


int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!c[i][j]) {
				num++;
				cnt[num] = dfs(i, j, num);
				if (max_value < cnt[num])
					max_value = cnt[num];
			}
		}	
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum = max2room(i, j);
			if (mx < sum)
				mx = sum;
		}
	}

	cout << num << endl; //规 俺荐
	cout << max_value << endl; //力老 承篮 规
	cout << mx << endl;

}