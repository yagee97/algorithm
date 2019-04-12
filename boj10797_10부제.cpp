#include <stdio.h>

int main()
{
	int n, car, cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &car);
		if (n == car)
			cnt++;
	}
	printf("%d", cnt);
}