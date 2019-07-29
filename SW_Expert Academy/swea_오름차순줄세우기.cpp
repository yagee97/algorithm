#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int test_case, T, temp;
int max_num;
int N, line[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		max_num = 0;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			line[temp] = line[temp - 1] + 1;
			max_num = max(max_num, line[temp]);
		}
		cout << "#" << test_case << " " << N - max_num << "\n";
		memset(line, 0, sizeof(line));
	}
	return 0;
}