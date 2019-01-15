#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int ll;
ll n, c;
ll house[200001];

ll search(ll left, ll right)
{
	ll result = 0;

	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll init = house[0], cnt=1;

		for (int i = 1; i < n; i++)
		{
			if (house[i] - init >= mid)
			{
				cnt++;
				init = house[i];
				if (cnt == c)
					break;
			}
		}
			if (cnt == c)
			{
				if (result < mid)
					result = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
	}
	return result;
}

int main()
{
	scanf("%lld%lld", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &house[i]);

	sort(house, house + n);

	ll left = 1, right = house[n - 1] - house[0];

	ll res = search(left, right);

	printf("%lld", res);
}