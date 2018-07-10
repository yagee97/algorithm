#include <stdio.h>

int main(void)
{
	int room[101];
	int test, num;
	int cnt = 0;

	scanf_s("%d", &test);

	while (test--)
	{
		scanf_s("%d", &num);
		for (int i = 1; i <= num; i++)
		{
			room[i] = 1;
		}

		for (int round = 2; round <= num; round++)
		{
			for (int m = 1; m <= num;m++)
			{
				if (m%round == 0)
				{
					room[m] = !room[m];
				}
			}
		}
		for (int i = 1; i <= num; i++)
		{
			cnt += room[i];
		}

		printf("%d\n", cnt);
		cnt = 0;
	}

}