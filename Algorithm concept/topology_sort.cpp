#include <iostream>
#include <queue>
#include <vector>
#define MAX 10

using namespace std;
int n;
int inDegree[MAX]; //��������
vector<int> a[MAX];//�� ������ ����Ǿ� �ִ� ������� ����

void topologySort()
{
	int result[MAX];
	queue<int> q;
	// ���������� 0�� ��� ť�� ����
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}
	// ���������� ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮�ؾ��Ѵ�.
	for (int i = 1; i <= n; i++) {
		// n���� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ �߻�
		if (q.empty()) {
			cout << "����Ŭ�� �߻��߽��ϴ�.";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x; // ť���� ���� ������ ���������� ������ ���
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// ���Ӱ� ���������� 0�̵� ������ q�� ����
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main()
{
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;

	topologySort();
}