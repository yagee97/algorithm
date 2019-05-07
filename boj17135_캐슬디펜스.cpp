#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct pos {
	int x, y;
};

struct Info {
	int x, y, z;
};

int n, m, d;
int map[20][20];
int cnt, result = 0;

Info info[3]; //한턴당 죽을 적 정보
vector<pos> e;
vector<pos> ancher;

int cal_dis(int x1, int y1, int x2, int y2) {
	int dis = abs(x1 - x2) + abs(y1 - y2);
	return dis;
}

void bfs()
{
	vector<pos> enermy;
	enermy = e;
	cnt = 0; //새로운 조합마다 cnt 초기화 필수
	while (1) {
		if (enermy.empty())
			break;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < enermy.size(); j++) {
				int dis = cal_dis(ancher[i].x, ancher[i].y, enermy[j].x, enermy[j].y);
				if (dis <= d && dis >= 1) {//d보다 작거나 같은 적
					if (info[i].z == 0) { //거리 계산해서 좌표랑 저장
						info[i].x = enermy[j].x;
						info[i].y = enermy[j].y;
						info[i].z = dis;
					}
					else {
						if (info[i].z > dis) {//가장 가까운 적
							info[i].x = enermy[j].x;
							info[i].y = enermy[j].y;
							info[i].z = dis;
						}
						else if (info[i].z == dis) {//거리 같으면
							if (info[i].y > enermy[j].y) {//왼쪽꺼
								info[i].x = enermy[j].x;
								info[i].y = enermy[j].y;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (info[i].z == 0)
				continue;
			for (int j = 0; j < enermy.size(); j++) {
				//죽을 적의 좌표와 적좌표가 같으면 죽이기.
				if (info[i].x == enermy[j].x && info[i].y == enermy[j].y) {
					cnt++;
					enermy.erase(enermy.begin() + j);
					break;
				}
			}
			info[i] = { 0,0,0 };
		}
		for (int i = 0; i < enermy.size(); i++)
			enermy[i].x++;

		for (int i = 0; i < enermy.size(); i++)
			if (enermy[i].x > n+1) {
				enermy.erase(enermy.begin() + i);
				i--;
			}
	}
	if (result < cnt)
		result = cnt;
}

void dfs(int idx, int cnt) //궁수선택
{
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = idx; i < m; i++) {
		ancher.push_back({ n,i });
		dfs(i+1, cnt + 1);
		ancher.pop_back();
	}
}

int main()
{
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				e.push_back({ i,j });
		}
	}

	dfs(0, 0);
	cout << result;
	
}