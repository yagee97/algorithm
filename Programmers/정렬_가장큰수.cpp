#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &str, const string &str2)
{
	return str + str2 > str2 + str;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;

	for (int i = 0; i < numbers.size(); i++) {
		str.push_back(to_string(numbers[i]));
	}

	sort(str.begin(), str.end(), cmp);

	for (int i = 0; i < str.size(); i++) {
		answer = answer + str[i];
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}