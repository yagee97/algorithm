#include <stdio.h>
#include <string.h>

using namespace std;
int T, H, W, N;
char map[22][22];
int cx, cy;

void solution(char ch)
{
	if (ch == 'U') {
		if (cx - 1 >= 0 && map[cx - 1][cy] == '.') {
			map[cx][cy] = '.';
			cx = cx - 1;
		}
		map[cx][cy] = '^';
	}
	else if (ch == 'D') {
		if (cx + 1 < H && map[cx + 1][cy] == '.') {
			map[cx][cy] = '.';
			cx = cx + 1;
		}
		map[cx][cy] = 'v';
	}
	else if (ch == 'L') {
		if (cy - 1 >= 0 && map[cx][cy - 1] == '.') {
			map[cx][cy] = '.';
			cy = cy - 1;
		}
		map[cx][cy] = '<';
	}
	else if (ch == 'R') {
		if (cy + 1 < W && map[cx][cy + 1] == '.') {
			map[cx][cy] = '.';
			cy = cy + 1;
		}
		map[cx][cy] = '>';
	}
	else if (ch == 'S') {
		if (map[cx][cy] == '^') {
			for (int i = cx - 1; i >= 0; i--) {
				if (map[i][cy] == '#') break;
				else if (map[i][cy] == '*') {
					map[i][cy] = '.';
					break;
				}
			}
		}
		else if (map[cx][cy] == 'v') {
			for (int i = cx + 1; i < H; i++) {
				if (map[i][cy] == '#') break;
				else if (map[i][cy] == '*') {
					map[i][cy] = '.';
					break;
				}
			}
		}
		else if (map[cx][cy] == '>') {
			for (int i = cy + 1; i < W; i++) {
				if (map[cx][i] == '#')break;
				else if (map[cx][i] == '*') {
					map[cx][i] = '.';
					break;
				}
			}
		}
		else if (map[cx][cy] == '<') {
			for (int i = cy - 1; i >= 0; i--) {
				if (map[cx][i] == '#')break;
				else if (map[cx][i] == '*') {
					map[cx][i] = '.';
					break;
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d\n", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d\n", &H, &W);
		for (int i = 0; i < H; i++) {
			scanf("%s", map[i]);
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '>' || map[i][j] == '<') {
					cx = i;
					cy = j;
					break;
				}
			}
		}
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			char ch;
			scanf("%c", &ch);
			solution(ch);
		}

		printf("#%d ", test_case);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}

		memset(map, 0, sizeof(map));
	}
}