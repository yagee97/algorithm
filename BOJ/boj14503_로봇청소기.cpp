//#include <iostream>
//
//using namespace std;
//
//int n, m, map[55][55];
//int x, y, dir;
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
//int cnt = 1;
//int main()
//{
//	cin >> n >> m;
//	cin >> x >> y >> dir;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	while (1)
//	{
//		map[x][y] = 2;
//		for (int i = 0; i < 4; i++) {
//			dir = (dir + 3) % 4;
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			if (map[nx][ny] == 0) {
//				x = nx;
//				y = ny;
//				cnt++;
//				break;
//			}
//		}
//		if (map[x][y] != 0) {
//			x = x - dx[dir];
//			y = y - dy[dir];
//			if (map[x][y] == 1)
//				break;
//		}
//	}
//	cout << cnt;
//}