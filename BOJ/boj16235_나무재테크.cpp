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
int A[11][11]; //�� ĭ�� �ų⸶�� �߰��Ǵ� ����� ��
vector<int>tree[11][11]; //�� ĭ�� �ִ� ���� ���� ����
int map[11][11]; //���� ��� ��

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
			//���̼� sorting
			//� �������� ��и԰� �ѻ� ����
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
			//�� ��ǥ���� ���� �� Ž�������� ���� ������Ʈ
			tree[i][j] = tmp;
			
		}
	}
}

void summer()
{
	//���� ������ �ִ� ��ǥ�� ��� �߰�
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
			map[i][j] = 5;//��� �ʱⰪ
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		//�� ��ǥ�� ���� ���� �ɾ����Ե� ����
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