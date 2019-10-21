#include <iostream>
#include <cmath>

using namespace std;
int N, L, ans;
int map[105][105], c[105][105];

void slope(int i, bool c)
{
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		int d;
		if (c == 1) {
			d = map[i][j + 1] - map[i][j];
		}
		else if (c == 0) {
			d = map[j + 1][i] - map[j][i];
		}
		if (d == 0) { //지금 칸이랑 다음칸이 같으면
			cnt++;
		}
		else if (d == 1 && cnt >= L)//차이가 1인데 연속된 칸이
			//경사로 길이만큼 있다면. 경사로 놓고 다시 cnt =1
			cnt = 1;
		else if (d == -1 && cnt >= 0)
			//차이가 -1. 즉 다음칸보다 내가 한칸더 위일때
			//앞으로 높이가 같은 칸이 -L+1만큼 있어야함. 그래서
			//cnt가 0보다 커지면 칸이 있는것. 
			cnt = -L + 1;
		else
			return; //조건 불충족. 걍 return;
	}
	if (cnt >= 0)
		ans += 1;
}

void solve()
{
	//행과 열 구분해서 길 세기
	for (int i = 0; i < N; i++) {
		slope(i, 1);
		slope(i, 0);
	}
	cout << ans << "\n";
}

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();

}