#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> input;
vector<int> v;
int visit[9];

bool check()
{
	for (int i = 0; i < v.size()-1; i++)
	{
		if (v[i] > v[i + 1]) return false;
	}
	return true;
}

void solve(int cnt)
{
	if (cnt == m)
	{
		if (check())
		{
			for (int i = 0; i < m; i++)
			{
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		return;
	}

	int c[10002] = { 0, };
	for (int i = 0; i < n; i++)
	{
		if (!c[input[i]] && !visit[i])
		{
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
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	solve(0);
}