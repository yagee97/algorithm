#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, map[25][25];
int d[25][25];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int fish_cnt = 0;
int result = 0;

struct Shark {
	int x;
	int y;
	int size;
	int eat;
};
Shark shark;

struct pos {
	int x;
	int y;
};

struct Fish {
	int x;
	int y;
	int dist;
};
vector<Fish> fish;

bool cmp(const Fish &a, const Fish &b)
{
	if (a.dist == b.dist) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
		}
	}
	return a.dist < b.dist;
}


//물고기마다 거리 계산.
void bfs()
{
	queue<pos> q;
	q.push({ shark.x, shark.y });
	d[shark.x][shark.y] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= n || ny >= n || nx < 0 || ny < 0)
				continue;
			if (d[nx][ny] == 0 && map[nx][ny] <= shark.size) {
				d[nx][ny] = d[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.eat = 0;
				// 상어있던칸 빈칸으로 만들기
				map[i][j] = 0;
			}
		}
	}
	
	while (1)
	{
		bfs();
		//한번 돌때마다 남아있는 물고기 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > 0 && map[i][j] < shark.size) {
					//먹을 수 있는 물고기
					int dist = d[i][j];
					if (dist > 0) {	
						fish.push_back({ i,j,dist });
					}
					
				}
			}
		}
		
		fish_cnt = (int)fish.size();
		//더이상 먹을 물고기 없으면 엄마 호출
		if (fish_cnt == 0)
			break;
		else if (fish_cnt > 0) {
			sort(fish.begin(), fish.end(), cmp);

			shark.eat++;
			if (shark.eat == shark.size) {
				shark.eat = 0;
				shark.size++;
			}
			
			int nx = fish[0].x;
			int ny = fish[0].y;
			int time = fish[0].dist;

			shark.x = nx;
			shark.y = ny;
			map[shark.x][shark.y] = 0;
			result += time;
			fish.clear();
			memset(d, 0, sizeof(d));
			
		}
	}
	cout << result;
}