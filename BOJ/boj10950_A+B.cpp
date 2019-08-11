#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		int num1,num2;
		scanf("%d %d", &num1, &num2);
		printf("%d\n", num1 + num2);
	}
}