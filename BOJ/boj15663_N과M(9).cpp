#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int> input;
vector<int> v;
int visit[9];

void solve(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	int c[10002] = { 0, };//하나기준으로 끝날때마다 초기화

	for (int i = 0; i < n; i++)
	{
		if (!c[input[i]] && !visit[i]) {
			c[input[i]] = true;
			visit[i] = true;

			v.push_back(input[i]);
			solve(cnt + 1);
			v.pop_back();
			visit[i] = false;
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
	solve(0);
}