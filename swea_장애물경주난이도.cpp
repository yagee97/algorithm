#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int t, n;
int map[1001];
int high = 0, low = 0;
int max1 = 0, max2 = 0;
int cnt = 0;
int main()
{
	cin >> t;
	while (t--)
	{
		cnt++;
		cin >> n;
		memset(map, 0, sizeof(map));
		max1 = 0, max2 = 0;

		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < n-1; i++) {
			if (map[i] < map[i + 1]) {
				high = map[i + 1] - map[i];
				max1 = max(max1, high);
			}
			else if (map[i] > map[i + 1]) {
				low = map[i] - map[i + 1];
				max2 = max(max2, low);
			}
		}
		cout << "#"<< cnt <<' '<< max1 << ' ' << max2 << endl;

		
	}

}