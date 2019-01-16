#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100001];
int m, b[100001];

void search(int n, int key)
{
	int left = 0;
	int right = n - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == key) {
			printf("1\n");
			return;
		}
		else if (a[mid] >= key) {
			right = mid - 1;
		}
		else if (a[mid] < key) {
			left = mid + 1;
		}
	}
	printf("0\n");
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);


	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		search(n, b[i]);
	}

}