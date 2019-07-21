#include <iostream>

using namespace std;
int number = 4;
int INF = 100000000;
//자료배열 초기화
int a[4][4] = {
	{0,5,INF,8},
{7,0,9,INF},
{2,INF,0,4},
{INF,INF,3,0}
};//비용

void floydWarshall()
{
	//결과 그래프 초기화
	int d[4][4];//모든 정점에서 모든정점으로 가는 최소비용
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k=거쳐가는 노드
	for (int k = 0; k < number; k++) {
		// i = 출발노드
		for (int i = 0; i < number; i++) {
			// j = 도착노드
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++) {
			cout << d[i][j] << ' ';
		}
	}
}
int main()
{
	floydWarshall();

}