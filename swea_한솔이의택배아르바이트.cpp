#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int t;
	cin >> t;

	for (int test_case = 1; test_case <= t; test_case++)
	{
		int cnt = 0;
		int n;
		int w[101];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);

		sort(&w[0], &w[n], compare);

		for (int i = 0; i < n; i++)
		{
			int idx = 1;
			if (w[i] >= 50)
			{
				cnt++;
			}
			else
			{
				while (i < n - 1)
				{
					n--;
					idx++;
					if (w[i] * idx >= 50)
					{
						cnt++;
						break;
					}
				}
			}
		}

		printf("#%d %d\n", test_case, cnt);
	}

	return 0;
}