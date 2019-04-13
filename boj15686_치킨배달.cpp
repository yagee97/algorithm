#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, map[55][55];
int ret = 1000000000;

class position {
public:
	int x, y;
	position(int a, int b) {
		this->x = a;
		this->y = b;
	}
};

vector<position> home;
vector<position> chicken;
vector<int> v;

void cal(int k, int cnt) {
	int sum = 0;
	if (chicken.size() < k) {
		return;
	}
	if (cnt == m) {
		for (int i = 0; i < home.size(); i++) {
			int mx = 1000000000;
			for (int j = 0; j < v.size(); j++) {
				int tmp = abs(home[i].x - chicken[v[j]].x) + abs(home[i].y - chicken[v[j]].y);
				mx = min(mx, tmp);
			}
			sum += mx;
		}
		ret = min(ret, sum);
		return;
	}

	v.push_back(k);
	cal(k + 1, cnt + 1);
	v.pop_back();
	cal(k + 1, cnt);
	//백트래킹 조합

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back({ i,j });
			if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	cal(0, 0);
	cout << ret;

}