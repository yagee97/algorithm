#include <cstdio>

using namespace std;

char puyo[12][8];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int xq[100], yq[100], k;
int c[12][6], result, cnt = 1;

void dfs(int x, int y) {
	c[x][y] = result;

	xq[k] = x; 
	yq[k++] = y;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0||nx>12 || ny>7 || puyo[nx][ny] != puyo[x][y] || c[nx][ny] == result)
			continue;
	
		dfs(nx, ny);
	}
}

void del() {
	cnt = 1;
	for (int i = 0; i < k; i++) {
		puyo[xq[i]][yq[i]] = '.';
	}
}

void search() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {

			if (puyo[i][j] != '.') {
				k = 0;
				dfs(i, j);

				if (k >= 4)
					del();
			}
		}
	}
}

void drop() {

	for (int i = 0; i < 6; i++) {

		int pad = puyo[11][i];
		if (pad == '.')
			pad = 1;
		else
			pad = 0;

		for (int j = 10; j >= 0; j--) {

			if (puyo[j][i] == '.') 
				pad++;
			else {
				char temp = puyo[j][i];
				puyo[j][i] = puyo[j + pad][i];
				puyo[j + pad][i] = temp;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 12; i++) 
		scanf("%s", &puyo[i]);

	while (cnt) {
		cnt = 0;
		result++;
		search();
		drop();
	}

	printf("%d", result - 1);
}