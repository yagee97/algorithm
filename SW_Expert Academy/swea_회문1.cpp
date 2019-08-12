#include <stdio.h>
#include <string>

using namespace std;
int L;
char map[8][8];
bool flag;

int ret = 0;
int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		ret = 0;
		scanf("%d", &L);

		for (int i = 0; i < 8; i++) {
			
				scanf("%s", map[i]);
			
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - L; j++) {
				flag = true;
				for (int k = 0; k < (L / 2); k++) {
					if (map[i][k + j] != map[i][L - (k-j) -1])
						flag = false;
				}
				if (flag)
					ret++;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - L; j++) {
				flag = true;
				for (int k = 0; k < L / 2; k++) {
					if (map[k + j][i] != map[L - (k - j) - 1][i]) {
						flag = false;
					}
				}
				if (flag) ret++;
			}
		}
		printf("#%d %d\n", test_case, ret);
	}
	
}