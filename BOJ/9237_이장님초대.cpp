#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n;
int tree[1000001];
int result = 0;
int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &tree[i]);

	sort(tree+1, tree + n + 1, greater<int>());

	for (int i = 1; i <= n; i++)
	{
		if (tree[i] + i > result)
			result = tree[i] + i;
	}

	printf("%d", result+1);

}