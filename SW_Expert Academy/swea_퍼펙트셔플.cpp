#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string input;
int T, N;
vector<string> str1;
vector<string> str2;
vector<string> result;

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{

		int cnt = 0;
		cin >> N;
		if (N % 2 == 1)
			cnt = N / 2+1;
		else
			cnt = N / 2;

		for (int i = 0; i < N; i++) {
			cin >> input;
			if (i < cnt)
				str1.push_back(input);
			else
				str2.push_back(input);
		}

		for (int i = 0; i < cnt; i++) {
			if (N % 2 == 1 && i == cnt-1) {
				result.push_back(str1[i]);
				break;
			}
			result.push_back(str1[i]);
			result.push_back(str2[i]);
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << "\n";
		str1.clear(); str2.clear(); result.clear();
	}
}