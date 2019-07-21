#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C ,M;

struct Shark {
	int s, d, z;
};
struct pos {
	int x, y, s,d,z;
};

Shark shark[101][101];
int result = 0;

void fishing()
{
	for (int k = 1; k <= C; k++) {

		for (int i = 1; i <= R; i++)
		{
			//같은 행에 상어가 있다면
			if (shark[i][k].z)
			{
				//잡기
				result += shark[i][k].z;
				//상어 없애기
				shark[i][k] = { 0,0,0 };
				break;
			}
		}

		//상어들 위치 갱신
		queue<pos> q;
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++) {
				q.push({ i,j,shark[i][j].s,shark[i][j].d,shark[i][j].z });
				shark[i][j] = { 0,0,0 };
			}
		}

		//상어 이동
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int size = q.front().z;
			int dir = q.front().d;
			int speed = q.front().s;
			q.pop();

			//이동
			for (int i = 0; i < speed; i++)
			{
				if (dir == 1) {
					if (x == 1) {
						dir = 2;
						//벽에 부딪히고 방향바꿔서 아래로 내려가야함.
						x++; 
					}
					else {
						x--;//벽 아니면 그냥 위로 올라가다가
						if (x == 1)//벽만나면 반대방향으로
							dir = 2;
					}
				}
				else if (dir == 2) {
					if (x == R) {
						dir = 1;
						x--;
					}
					else {
						x++;
						if (x == R)
							dir = 1;
					}
				}
				else if (dir == 3) {
					if (y == C) {
						dir = 4;
						y--;
					}
					else {
						y++;
						if (y == C)
							dir = 4;
					}
				}
				else if (dir == 4) {
					if (y == 1) {
						dir = 3;
						y++;
					}
					else {
						y--;
						if (y == 1)
							dir = 3;
					}
				}
			}
			//칸에 이미 상어 있으면 크기 비교
			if (shark[x][y].z) {
				//size가 지금 이동한 상어 크기
				if (shark[x][y].z < size) {
					shark[x][y] = { 0,0,0 };//기존상어 없애고
					shark[x][y] = { speed,dir,size };
				}
			}
			else {
				shark[x][y] = { speed,dir,size };
			}

		}
	}
}

int main()
{
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		//상어 위치에 그 상어 정보 넣기
		shark[r][c] = { s,d,z };
	}

	fishing();
	cout << result;
	
}