#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m,s,v;
double mouse[101][101], tunnel[101][101];
int b[101];
int result = 0;
bool visited[101];
vector<vector<int>> node;

int dfs(int here)
{
	if (visited[here])//�̸̹�Ī��
		return 0;
	visited[here] = true;//�湮�ߴٰ� ����
	for (int i = 0; i < node[here].size(); i++) {
		int there = node[here][i];
		if (!b[there] || dfs(b[there]))//��Īx or �̸̹�Ī�� ���� �ٸ� ���� ��Ī �����Ҷ�
		{
			b[there] = here;
			return 1;
		}
	}
	return 0;
}

int bmatch()
{
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			result++;
	}
	return result;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &v);
	node.resize(n+1);

	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &mouse[i][0],&mouse[i][1]);

	for (int i = 1; i <= m; i++)
		scanf("%lf%lf", &tunnel[i][0], &tunnel[i][1]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		{
			if (sqrt((mouse[i][0] - tunnel[j][0]) * (mouse[i][0] - tunnel[j][0]) + (mouse[i][1] - tunnel[j][1])*(mouse[i][1] - tunnel[j][1])) <= (double)s*v)
				node[i].push_back(j);
			//�㰡 ������ ���� �ӵ��� �Ű� ���� �ð����� ���ų� �������
		}
	}
	printf("%d", n - bmatch());//�ִ��Ī�� ������ ��������� ��
	return 0;

}