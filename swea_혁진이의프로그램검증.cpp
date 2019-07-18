#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int T, R, C;
char map[20][20];
int visit[4][15][20][20];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct point
{
	int x, y, d, m;
};
bool bfs()
{
	queue <point> q;
	q.push({ 0,0,0,0 });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().d;
		int m = q.front().m;
		q.pop();

		if (map[y][x] - '0' >= 0 && map[y][x] - '0' <= 9)
		{
			m = map[y][x] - '0';
		}

		if (map[y][x] == '>')
			dir = 0;
		else if (map[y][x] == '<')
			dir = 1;
		else if (map[y][x] == '^')
			dir = 2;
		else if (map[y][x] == 'v')
			dir = 3;
		else if (map[y][x] == '+')
		{
			if (m == 15)
			{
				m = 0;
			}
			else
				m++;
		}
		else if (map[y][x] == '-')
		{
			if (m == 0)
			{
				m = 15;
			}
			else
				m--;
		}
		else if (map[y][x] == '_')
		{
			if (m == 0)//memory�� 0�̸� �������������
			{
				dir = 0;
			}
			else//�ƴϸ� ��������
			{
				dir = 1;
			}
		}
		else if (map[y][x] == '|')
		{
			if (m == 0)//0�̸� �Ʒ���
			{
				dir = 3;
			}
			else//�ƴϸ� ����
			{
				dir = 2;
			}
		}
		else if (map[y][x] == '@')//����
		{
			return true;
		}
		if (map[y][x] == '?')//�����¿� ����
		{
			for (int i = 0; i < 4; i++)
			{
				if (visit[i][m][y][x] == 0)//�غ��� ���� ��Ʈ��
				{
					visit[i][m][y][x] = 1;//�غô� ǥ��
					//��� ���⿡ ���� �˻�
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx == -1) 
						nx = C - 1;
					else if (nx == C) 
						nx = 0;
					if (ny == -1) 
						ny = R - 1;
					else if (ny == R) 
						ny = 0;

					q.push({ nx,ny,i,m });
				}
			}
		}
		else
		{
			if (visit[dir][m][y][x] == 0)
			{
				visit[dir][m][y][x] = 1;
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx == -1) 
					nx = C - 1;
				else if (nx == C) 
					nx = 0;
				if (ny == -1) 
					ny = R - 1;
				else if (ny == R) 
					ny = 0;

				q.push({ nx,ny,dir,m });
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				scanf("%1s", &map[i][j]);//�Ѱ����ޱ�
			}
		}
		if (bfs())
		{
			printf("#%d %s\n", test_case, "YES");
		}
		else
		{
			printf("#%d %s\n", test_case, "NO");
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				map[i][j] = 0;
			}
		}
		memset(&visit, 0, sizeof(visit));
	}
}