#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

typedef pair<int, int> pos;
vector<pos> location;

int t, n;
bool check[102][102] = { false, };

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		location.resize(n + 2);

		for (int i = 0; i < n + 2; i++)
		{
			scanf("%d%d", &location[i].first, &location[i].second);
		}

		memset(check, false, sizeof(check));

		for (int i = 0; i < location.size(); i++)
		{
			for (int j = 0; j < location.size(); j++)
			{
				if (i == j)
					continue;
				int dis = abs(location[i].first - location[j].first) + abs(location[i].second - location[j].second);

				if (dis <= 1000)
					check[i][j] = true;
			}
		}

		for (int k = 0; k < n + 2; k++)
		{
			for (int i = 0; i < n + 2; i++)
			{
				for (int j = 0; j < n + 2; j++)
				{
					if (!check[i][j]) {
						if (check[i][k] && check[k][j])
							check[i][j] = true;
					}

				}
			}
		}
		if (check[0][n+1])
			printf("happy\n");
		else
			printf("sad\n");
	}
	location.clear();

}