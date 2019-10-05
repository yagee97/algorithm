#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, num[15];
int oper[4];
int cnt = 0;
int MAX = -1000000001, MIN = 1000000001;
vector<int> v;

void solve(int idx, int total) {
	if (idx == n)
	{
		//max, minºñ±³
		MAX = max(MAX, total);
		MIN = min(MIN, total);
		return;
	}

	if (oper[0] > 0) {
		oper[0]--;
		solve(idx + 1, total + num[idx]);
		oper[0]++;
	}
	if (oper[1] > 0) {
		oper[1]--;
		solve(idx + 1, total - num[idx]);
		oper[1]++;
	}
	if (oper[2] > 0) {
		oper[2]--;
		solve(idx + 1, total * num[idx]);
		oper[2]++;
	}
	if (oper[3] > 0) {
		oper[3]--;
		solve(idx + 1, total / num[idx]);
		oper[3]++;
	}
	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	solve(1, num[0]);
	cout << MAX << "\n";
	cout << MIN << "\n";
}