#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, map[25][25];
int team[25 * 25];
int ret = 1e9;

void cal(int idx, int cnt)
{
	if (idx == n)
		return;

	if (cnt == n / 2) {
		int A = 0, B = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (team[i] && team[j])
					A += map[i][j];
				else if (!team[i] && !team[j])
					B += map[i][j];
			}
		}
		int tmp = abs(A - B);
		ret = min(ret, tmp);
		return;
	}

	team[idx] = true;
	cal(idx + 1, cnt + 1);
	team[idx] = false;
	cal(idx + 1, cnt);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cal(0, 0);
	cout << ret;

}