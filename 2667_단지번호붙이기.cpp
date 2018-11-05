#include<cstdio>
#include<algorithm>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int n,cnt;
int apart[27][27];
int result[26 * 26];

void dfs(int x, int y) {

	if (!apart[x][y]) 
		return;
	
	apart[x][y] = 0;
	result[cnt]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny);
	}
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			scanf("%1d", &apart[i][j]);//한개씩 받기
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (apart[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	sort(result, result + cnt);

	for (int i = 0; i < cnt; i++)
		printf("%d\n", result[i]);

	return 0;
}