#include <iostream>
#include <vector>
#include <map>
#define INF 10000000
using namespace std;

int n, m;
int a[105][105];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k]&&a[k][j]) {
					a[i][j] = 1;
				}
			}
		}
	}
	
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = 0;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0 && a[j][i] == 0)
				ret++;
		}
		cout << ret-1 << endl;
	}

}