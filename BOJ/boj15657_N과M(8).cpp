#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
vector<int> input;
int n, m;

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
		if (check()) {
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		v.push_back(input[i]);
		solve(cnt + 1);
		v.pop_back();
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