#include <iostream>

using namespace std;
double pro[4];
int n;
int c[30][30] = { false, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

double dfs(int x, int y, int cnt)
{
	double ret = 0.0;
	if (cnt == 0)
		return 1;
	c[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//단순한 경로일 때만 확률 곱해서 더하기
		//cnt가 0이 되면, 단순한 경로
		if (!c[nx][ny]) {
			ret += dfs(nx, ny, cnt - 1) * pro[i];
		}
	}
	c[x][y] = false;
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> pro[i];
		pro[i] = pro[i] / 100.0;
	}
	//절대오차 있을 때 꼭 출력범위 확인하기
	cout.precision(11);
	cout << fixed;
	cout << dfs(15, 15, n);

}