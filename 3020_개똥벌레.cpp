#include <iostream>
#include <algorithm>

using namespace std;
int bottom_search(int h);
int top_search(int h);

int n,h;
int top[500001], bottom[500001];

int main(void)
{
	int min = 999999;
	int result,num;

	scanf_s("%d%d", &n, &h);

	for (int i = 1; i <= n/2; i++)
	{
		scanf_s("%d", &top[i]);
		scanf_s("%d", &bottom[i]);
	}

	sort(top + 1, top + (n / 2) + 1);
	sort(bottom+1, bottom + (n / 2) + 1);

	for (int i = 1; i <= h; i++) {
		int tmp = top_search(i) + bottom_search(h - i + 1);
		if (tmp < min) {
			min = tmp;
			result = 1;
		}
		else if (tmp == min) {
			result += 1;
		}
	}
	printf("%d %d", min, result);

}
int top_search(int h)
{
	int p = 0;
	int s_result = 0;
	int left = 1, right = n / 2;
	while (left <= right)
	{
		int m = (left + right) / 2;

		if (top[m] < h) {
			left = m + 1;
		}
		else {
			p = m;
			right = m - 1;
		}
	}

	if (p == 0) return 0;

	s_result = n / 2 - p + 1;
	return s_result;
}

int bottom_search(int h)
{
	int p = 0;
	int s_result = 0;
	int left = 1, right = n / 2;
	while (left <= right)
	{
		int m = (left + right) / 2;

		if (bottom[m] < h) {
			left = m + 1;
		}
		else {
			p = m;
			right = m - 1;
		}
	}
	if (p == 0) return 0;

	s_result = n / 2 - p + 1;
	return s_result;
}