#include <iostream>
#include <cmath>

using namespace std;

int t, n, m;
int map[1002][1002];
int dx[2] = { 2,0 };
int dy[2] = { 0,2 };
int result = 0;
int cnt = 1;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		result = n * m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0)//이미 콩 x
					continue;
				for (int k = 0; k < 2; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					//기준점에서 거리 2 안에 콩이 심어져 있으면, 없애기
					if (nx < n && ny < m && map[nx][ny] == 1) {
						map[nx][ny] = 0;
						result--;
					}

				}
				
			}
		}
		cout << "# "<< cnt << " "<< result << endl;
		cnt++;
	}
	


}