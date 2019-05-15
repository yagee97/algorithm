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
			//���� �࿡ �� �ִٸ�
			if (shark[i][k].z)
			{
				//���
				result += shark[i][k].z;
				//��� ���ֱ�
				shark[i][k] = { 0,0,0 };
				break;
			}
		}

		//���� ��ġ ����
		queue<pos> q;
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++) {
				q.push({ i,j,shark[i][j].s,shark[i][j].d,shark[i][j].z });
				shark[i][j] = { 0,0,0 };
			}
		}

		//��� �̵�
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int size = q.front().z;
			int dir = q.front().d;
			int speed = q.front().s;
			q.pop();

			//�̵�
			for (int i = 0; i < speed; i++)
			{
				if (dir == 1) {
					if (x == 1) {
						dir = 2;
						//���� �ε����� ����ٲ㼭 �Ʒ��� ����������.
						x++; 
					}
					else {
						x--;//�� �ƴϸ� �׳� ���� �ö󰡴ٰ�
						if (x == 1)//�������� �ݴ��������
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
			//ĭ�� �̹� ��� ������ ũ�� ��
			if (shark[x][y].z) {
				//size�� ���� �̵��� ��� ũ��
				if (shark[x][y].z < size) {
					shark[x][y] = { 0,0,0 };//������� ���ְ�
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
		//��� ��ġ�� �� ��� ���� �ֱ�
		shark[r][c] = { s,d,z };
	}

	fishing();
	cout << result;
	
}