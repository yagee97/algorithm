#include <iostream>
#include <queue>
#include <vector>
#define MAX 10

using namespace std;
int n;
int inDegree[MAX]; //진입차수
vector<int> a[MAX];//각 정점에 연결되어 있는 노드정보 담음

void topologySort()
{
	int result[MAX];
	queue<int> q;
	// 진입차수가 0인 노드 큐에 삽입
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}
	// 위상정렬이 완전히 수행되려면 정확히 n개의 노드를 방문해야한다.
	for (int i = 1; i <= n; i++) {
		// n개를 방문하기 전에 큐가 빈다면 사이클 발생
		if (q.empty()) {
			cout << "사이클이 발생했습니다.";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x; // 큐에서 꺼낸 순서가 위상정렬을 수행한 결과
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// 새롭게 진입차수가 0이된 정점을 q에 삽입
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