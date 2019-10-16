#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int x;
	int y;
	int age;
};

int tmp = 0;
int n, m, K;
int A[11][11]; //각 칸에 매년마다 추가되는 양분의 값
vector<int>tree[11][11]; //각 칸에 있는 나무 나이 정보
int map[11][11]; //현재 양분 값

vector<info> dead;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void spring()
{
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].empty())
				continue;
		vector<int> tmp;
			//나이순 sorting
			//어린 나무부터 양분먹고 한살 증가
			sort(tree[i][j].begin(), tree[i][j].end());
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (map[i][j] >= age) {
					map[i][j] -= age;
					tmp.push_back(age + 1);
				}
				else {
					dead.push_back({ i,j,age / 2 });
				}
			}
			//한 좌표에서 나무 다 탐색했으면 나이 업데이트
			tree[i][j] = tmp;
			
		}
	}
}

void summer()
{
	//죽은 나무가 있던 좌표에 양분 추가
	for (int i = 0; i < dead.size(); i++) {
		int x = dead[i].x;
		int y = dead[i].y;
		int age = dead[i].age;

		map[x][y] += age;
	}
	dead.clear();
}

void autumn()
{

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (age % 5 == 0)
				{
					for (int s = 0; s < 8; s++) {
						int nx = i + dx[s];
						int ny = j + dy[s];

						if (nx > n || ny > n || nx < 1 || ny < 1)
							continue;

						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}
	


void winter()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] += A[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> K;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			map[i][j] = 5;//양분 초기값
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		//한 좌표에 여러 나무 심어지게도 가능
		tree[x][y].push_back(z);
	}

	while (K--) {
		spring();
		summer();
		autumn();
		winter();
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ret += tree[i][j].size();
		}
	}
	cout << ret;

}