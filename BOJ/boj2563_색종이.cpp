#include <stdio.h>

int n;
int check[101][101] = {false,};
int width = 0;
int main()
{

	scanf("%d", &n);

	for (int t = 0; t < n; t++)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		for (int i = r; i < r + 10; i++) {
			for (int j = c; j < c + 10; j++) {
				check[i][j] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (check[i][j]) {
				width++;
			}

		}
	}

	printf("%d", width);

}