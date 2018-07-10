#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int c[300000];
int cnt_jewel = 0;

long long result=0;
pair <int, int> jewel[300000];
priority_queue<int> q;

int main(void)
{

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &jewel[i].first, &jewel[i].second);
	}

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &c[i]);
	}

	sort(jewel, jewel + n);
	sort(c, c + k);

	for (int i = 0; i < k; i++)
	{
		while (cnt_jewel < n && jewel[cnt_jewel].first <= c[i])
		{
			q.push(jewel[cnt_jewel].second);
			cnt_jewel++;
		}

		if (!q.empty())
		{
			result = result + q.top();
			q.pop();
		}
	}
	printf("%lld", result);


}