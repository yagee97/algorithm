#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int result = 0;
int R, C, T,map[60][60];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int c[60][60] = { 0, };
int airX, airY, air2X, air2Y;
int ccw[] = {2,0,3,1};
int cw[] = {2,1,3,0};

//map원본 가지고 있기 위해 map copy
void mapcopy(int map[60][60], int new_map[60][60])
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			new_map[i][j] = map[i][j];
		}
	}
}

void spread()
{
	int new_map[60][60];

	mapcopy(map, new_map);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) {
			//공기청정기 x, 빈칸x
			if (map[i][j] != 0 && map[i][j] != -1) {
				int cnt = 0;
				int value = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					
					if (nx >= 0 && ny >= 0 && nx < R && ny < C)
					{
						if (map[nx][ny] != -1)
						{
							//미세먼지 뿌리기
							new_map[nx][ny] += value;
							cnt++;
						}
					}
				}
				//현재칸 남은 미세먼지
				new_map[i][j] -= (cnt * value);
			}
		}
	}
	mapcopy(new_map, map);
}

void rotate()
{
	int new_map[60][60];
	mapcopy(map, new_map);

	int x = airX;
	int y = airY+1;
	map[x][y] = 0;
	
	//ccw
	for (int i = 0; i < 4; i++)
	{
		while (1)
		{
			int nx = x + dx[ccw[i]];
			int ny = y + dy[ccw[i]];

			if (nx == airX && ny == airY)
				break;
			if (!(0 <= nx && nx < R && ny >= 0 && ny < C))
				break;

			map[nx][ny] = new_map[x][y];
			x = nx;
			y = ny;

		}
	}

	x = air2X;
	y = air2Y+1;
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		while (1) {
			int nx = x + dx[cw[i]];
			int ny = y + dy[cw[i]];
			//한바퀴 돌고 돌아오면 끝
			if (nx == air2X && ny == air2Y)
				break;
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				break;

			map[nx][ny] = new_map[x][y];
			x = nx;
			y = ny;
		}
	}
}

int main()
{
	cin >> R >> C >> T;
	int tmp = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (tmp == 0) {
					airX = i;
					airY = j;
					tmp++;
				}
				else {
					air2X = i;
					air2Y = j;
				}
			}
		}
	}
	for (int i = 0; i < T; i++) {
		spread();
		rotate();
	}
	result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] >= 1)
				result += map[i][j];
		}
	}
	cout << result;
}