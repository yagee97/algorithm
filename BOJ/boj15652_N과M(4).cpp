#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;

bool check()
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1]) return false;
	}
	return true;
}

void solve(int cnt)
{
	if (cnt == m)
	{
		if (check()) {
			for (int i = 0; i < m; i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		solve(cnt + 1);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	solve(0);
}