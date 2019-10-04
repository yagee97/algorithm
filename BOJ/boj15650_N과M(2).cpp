#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool c[9];
vector<int> v;

void solve(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (!c[i]) {
			c[i] = true;
			v.push_back(i);
			solve(cnt + 1, i + 1);
			v.pop_back();
			c[i] = false;
		}
	}
}
int main()
{
	cin >> n >> m;
	solve(0, 1);
}