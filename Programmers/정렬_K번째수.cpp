#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int i, j, k;
	for (int t = 0; t < commands.size(); t++) {
		vector<int> array2;
		i = commands[t][0];
		j = commands[t][1];
		k = commands[t][2];
		array2.assign(array.begin() + i - 1, array.begin() + j);
		sort(array2.begin(), array2.end());
		answer.push_back(array2[k - 1]);
	}

	return answer;
}