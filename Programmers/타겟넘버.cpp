#include <string>
#include <vector>

using namespace std;
int ans = 0;
void dfs(vector<int> numbers, int target, int sum, int idx)
{
	int size = numbers.size();

	if (idx >= size) {
		if (sum == target) {
			ans++;
			return;
		}
		return;
	}

	dfs(numbers, target, sum + numbers[idx], idx + 1);
	dfs(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	ans = 0;

	dfs(numbers, target, 0, 0);
	answer = ans;
	return answer;
}