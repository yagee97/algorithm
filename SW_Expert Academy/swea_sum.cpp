#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
int T, map[101][101];
int row_sum[101] = { 0, };
int col_sum[101] = { 0, };
int diagonal_sum[101] = { 0, };


int main(void)
{

	for (int test_case = 1; test_case <= 10; test_case++)
	{
		scanf("%d", &T);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				row_sum[i] += map[i][j];
				col_sum[i] += map[j][i];
			}
		}
		for (int i = 100; i > 0; i--) {
			for (int j = 0; j < 100; j++) {
				diagonal_sum[j] += map[i][j];
			}
		}

		int row_max, col_max, diag_max;
		row_max = *max_element(row_sum, row_sum + 101);
		col_max = *max_element(col_sum, col_sum + 101);
		diag_max = *max_element(diagonal_sum, diagonal_sum + 101);

		printf("#%d %d\n", test_case, max(diag_max, max(row_max, col_max)));

		memset(row_sum, 0, sizeof(row_sum));
		memset(col_sum, 0, sizeof(row_sum));
		memset(diagonal_sum, 0, sizeof(row_sum));

	}
}