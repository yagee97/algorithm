#include <iostream>
#include <vector>

using namespace std;
int n, m, k;
int A[52][52];
int ans = 100000;

typedef struct {
	int r;
	int c;
	int s;
}info;

vector<info> oper;
int c[6];

void rotate(int index, int map[52][52])
{
	int r = oper[index].r;
	int c = oper[index].c;
	int s = oper[index].s;

	while (s > 0)
	{
		int temp = map[r - s][c - s];
		int temp2 = map[r + s][c - s];

		for (int i = c - s; i < c + s; i++) {
			map[r + s][i] = map[r + s][i + 1];
		}

		for (int i = r - s; i < r + s; i++) {
			map[i][c - s] = map[i + 1][c - s];
		}
		
		for (int i = r + s; i > r - s; i--) {
			map[i][c+s] = map[i-1][c+s];
		}

		for (int i = c + s; i > c - s; i--) {
			map[r-s][i] = map[r-s][i-1];
		}
		map[r - s][c - s + 1] = temp;
		map[r + s - 1][c - s] = temp2;
		s--;
	}
}

void arrcpy(int map[52][52], int newmap[52][52])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			newmap[i][j] = map[i][j];
		}
	}
}

void cal(int map[52][52])
{
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum = sum + map[i][j];
		}
		if (ans > sum) {
			ans = sum;
		}
	}
}

void dfs(int idx, int map[52][52])
{
	if (idx == k) {
		//최솟값 계산
		cal(map);
		return;
	}

	for (int i = 0; i < k; i++) {
		if (!c[i]) {
			c[i] = true;

			//map copy
			int new_map[52][52];
			arrcpy(map, new_map);

			//rotate 조합
			rotate(i, new_map);
			dfs(idx + 1, new_map);
			c[i] = false;
		}
	}

}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		oper.push_back({ r-1,c-1,s });
	}

	dfs(0, A);
	cout << ans << "\n";
}