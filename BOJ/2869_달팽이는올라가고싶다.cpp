#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a,b,v;
long long search();

int main(void)
{
	scanf("%d%d%d", &a, &b, &v);
	long long result;
	result = search();
	printf("%lli",result);

}

long long search()

{
	long long left = 0, right = v / (a - b) + 1;
	long long mid;
	long long day = 1000000001;

	while (left <= right)

	{

		mid = (left + right) / 2;

		if (v <= mid * (a - b) + a)
		{
			day = min(day, mid + 1);
			right = mid - 1;

		}
		else
			left = mid + 1;

	}

	return day;
}