#include <stdio.h>
int height[9];

void sort(int height[]);
int main(void)
{
	int total = 0;
	int i, j;
	int result = 0;

	for (int cnt = 0; cnt < 9; cnt++)
	{
		scanf_s("%d", &height[cnt]);
		total = total + height[cnt];
	}

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			result = total - (height[i] + height[j]);
			if (result == 100)
			{
				height[i] = 100;
				height[j] = 100;
				i = 8;
			}
		}
	}

	sort(height);

	for (int k = 0; k < 7; k++)
	{
		printf("%d\n", height[k]);
	}

}

void sort(int height[])
{
	int temp = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++) {
			if (height[i] > height[j])
			{
				temp = height[i];
				height[i] = height[j];
				height[j] = temp;
			}
		}
	}
	
}
