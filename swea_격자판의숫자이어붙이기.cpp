#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
int t, map[5][5];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
set<string> makeNum;

void dfs(int x, int y, int cnt, string s)
{
	s += map[x][y];//새로운 숫자만들기
	cnt++;
	if (cnt == 7) {
		makeNum.insert(s);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			continue;
		dfs(nx, ny, cnt, s);
	}
}

int main()
{
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) 
	{
		makeNum = set<string>();//초기화
		memset(map, 0, sizeof(map));

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 0, "");
			}
		}
		printf("#%d %d\n", test_case, makeNum.size());

	}
}