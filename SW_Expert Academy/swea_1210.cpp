#include <iostream>
#include <string.h>

using namespace std;
int ladder[101][101];
int check[101][101] = { 0, };
int dx[] = { 0,0,-1 };
int dy[] = { -1,1,0 };
int result = 0;

void dfs(int x, int y) {
	if (x == 0) {
		result = y;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100)
			continue;
		if (!check[nx][ny] && ladder[nx][ny] == 1) {
			check[nx][ny] = true;
			//다양한 경로가 있을 때 가지치기 필요. 최종값 변하지 않게
			return dfs(nx, ny);
		}
	}
}

int main(void)
{
	int dest_x = 0, dest_y = 0;
	for (int test_case = 1; test_case <= 10; test_case++) {
		int t;
		cin >> t;
		memset(ladder, 0, sizeof(ladder));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> ladder[i][j];
				if (ladder[i][j] == 2) {
					dest_x = i;
					dest_y = j;
				}
			}
		}
		result = 0;
		dfs(dest_x, dest_y);
		cout << "#" << test_case << " " << result << "\n";
	}
}