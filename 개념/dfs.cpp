#include <iostream>
#include <vector>

using namespace std;

int num = 7;
int c[8];
vector<int> a[8];

void dfs(int x)
{
	if (c[x]) return;
	c[x] = true; //ó���湮�̸� �湮ó��
	cout << x << ' ';

	for (int i = 0; i < a[x].size(); i++) //�������
	{
		int y = a[x][i];
		dfs(y);//������� ������� dfs����.
	}
}

int main(void) {

	a[1].push_back(2);
	a[2].push_back(1); //���� ����Ǿ� �ִٴ� ���� ǥ��. ����

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(8);

	dfs(1);
	return 0;
}