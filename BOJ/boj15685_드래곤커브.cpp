#include <iostream>
#include <vector>

using namespace std;
int map[101][101];
int c[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = {0,-1,0,1};

int main()
{
	int x, y, d, g;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> x >> y >> d >> g;

		vector<int> dragon;
		dragon.push_back(d);

		for (int j = 0; j < g; j++) {
			
			vector<int> tmp = dragon;
			//¿ª¼ö·Î
			for (int k = tmp.size()-1; k >=0 ; k--)
			{
				dragon.push_back((tmp[k] + 1) % 4);
			}
		}

		c[x][y] = true;
		for (int s = 0; s < dragon.size(); s++)
		{
			x = x + dx[dragon[s]];
			y = y + dy[dragon[s]];

			if (x >= 0 && x < 101 && y >= 0 && y < 101)
				c[x][y] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if(c[i][j] && c[i+1][j] && c[i+1][j+1] && c[i][j+1])
			{
				ans++;
			}
		}
	}
	cout << ans;
}