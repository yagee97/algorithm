#include <stdio.h>

int main()
{
	int price;
	int min1 = 0, min2 = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &price);
		if (i == 0)
			min1 = price;
		if (min1 > price)
			min1 = price;
	}

	for (int i = 0; i < 2; i++) {
		scanf("%d", &price);
		if (i == 0)
			min2 = price;
		if (min2 > price)
			min2 = price;
	}
	printf("%d", min1+min2-50);
}