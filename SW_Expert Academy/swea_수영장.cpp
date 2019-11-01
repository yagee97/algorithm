#include <iostream>

using namespace std;
int T, plan[12], tmp[12];
int amount[4] = { 0,0,0,0 };
int ans = 987654321;
int day, month, three_month, year;

int total()
{
	int sum = 0;
	for (int i = 1; i <= 12; i++)
	{
		if (tmp[i] == 0)
			continue;
		else if (tmp[i] == 1) {
			sum += day * plan[i];
		}
		else if (tmp[i] == 2) {
			sum += month;
		}
		else if (tmp[i] == 3) {
			sum += three_month;
			i += 2;//¼¼´ŞÄ¡
		}
	}
	return sum;
}

void dfs(int x)
{
	if (x > 12)
	{
		int ret = total();
		if (ans > ret)
			ans = ret;
		return;
	}

	if (plan[x] == 0) {
		tmp[x] = 0;
		dfs(x + 1);
	}
	else if (plan[x] != 0) {
		tmp[x] = 1;
		dfs(x + 1);
		tmp[x] = 2;
		dfs(x + 1);
		tmp[x] = 3;
		dfs(x + 1);
	}
}
int main()
{
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		ans = 987654321;

		cin >> day >> month >> three_month >> year;

		for (int i = 1; i <= 12; i++) {
			cin >> plan[i];
		}
		dfs(1);
		if (ans > year) {
			ans = year;
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
}