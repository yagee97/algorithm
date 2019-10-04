#include <iostream>

using namespace std;
int n, m;
int arr[9];
bool c[9];

void solve(int cnt)
{

	if (cnt == m)
	{
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!c[i]) {
			c[i] = true;
			arr[cnt] = i;
			solve(cnt + 1);
			c[i] = false;
		}
	}

}

int main()
{
	cin >> n >> m;
	solve(0);

}