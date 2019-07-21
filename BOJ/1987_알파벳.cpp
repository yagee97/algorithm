#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
char board[21][21];
bool check[26];
int Max = 0;
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

void dfs(int row, int colurm, int depth)
{
	Max = max(Max, depth);
	check[board[row][colurm] - 'A'] = true;
	for (int dir = 0; dir < 4; dir++) {
		if (row + dx[dir] < 0 || row + dx[dir] >= r || colurm + dy[dir] < 0 || colurm + dy[dir] >= c)
			continue;
		if (check[board[row + dx[dir]][colurm + dy[dir]] - 'A'])
			continue;
		dfs(row + dx[dir], colurm + dy[dir], depth + 1);
	}
	check[board[row][colurm] - 'A'] = false;

}

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		scanf("%s", board[i]);
	}
	dfs(0, 0, 1);
	printf("%d", Max);
}