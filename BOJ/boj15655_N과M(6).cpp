#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> input;
int n, m, c[9];

void solve(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (!c[i]) {
			c[i] = true;
			v.push_back(input[i]);
			solve(cnt + 1, i+1);
			v.pop_back();
			c[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	solve(0,0);
}