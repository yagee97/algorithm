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

Info info[3]; //���ϴ� ���� �� ����
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
	cnt = 0; //���ο� ���ո��� cnt �ʱ�ȭ �ʼ�
	while (1) {
		if (enermy.empty())
			break;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < enermy.size(); j++) {
				int dis = cal_dis(ancher[i].x, ancher[i].y, enermy[j].x, enermy[j].y);
				if (dis <= d && dis >= 1) {//d���� �۰ų� ���� ��
					if (info[i].z == 0) { //�Ÿ� ����ؼ� ��ǥ�� ����
						info[i].x = enermy[j].x;
						info[i].y = enermy[j].y;
						info[i].z = dis;
					}
					else {
						if (info[i].z > dis) {//���� ����� ��
							info[i].x = enermy[j].x;
							info[i].y = enermy[j].y;
							info[i].z = dis;
						}
						else if (info[i].z == dis) {//�Ÿ� ������
							if (info[i].y > enermy[j].y) {//���ʲ�
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
				//���� ���� ��ǥ�� ����ǥ�� ������ ���̱�.
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

void dfs(int idx, int cnt) //�ü�����
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