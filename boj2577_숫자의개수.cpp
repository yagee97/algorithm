#include <stdio.h>

int main()
{
	int a, b, c, mul;
	scanf("%d%d%d", &a, &b, &c);
	mul = a * b * c;
	int ret[11] = {0,};

	for (int i = 0; i < 9; i++)
	{
		ret[mul%10]++;
		mul = mul / 10;
		if (mul <= 0)
			break;
	}

	for (int i = 0; i <= 9; i++) {
		printf("%d\n", ret[i]);
	}

}