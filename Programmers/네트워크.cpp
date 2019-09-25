#include <string>
#include <vector>
#include <string.h>

using namespace std;
bool c[202];

void dfs(int start, vector<vector<int>> &computers, int n) {
	c[start] = 1;

	for (int i = 0; i < n; i++) {
		if (!c[i] && computers[start][i]) {
			dfs(i, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			answer++;
			dfs(i, computers, n);
		}
	}
	return answer;
}