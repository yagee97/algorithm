#include <iostream>
#include <vector>

using namespace std;
int k, lotto[14];
int c[14] = {0,};
int ret[14];

void dfs(int x, int cnt) {

	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ret[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = x; i < k; i++) {
		ret[cnt] = lotto[i];
		dfs(i + 1, cnt + 1);
	}
}
int main()
{
	while (1) {
		cin >> k;
		if (!k) break;
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << '\n';

	}
	return 0;

}