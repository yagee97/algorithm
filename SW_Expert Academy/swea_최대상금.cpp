#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> v;
string init_num;
int max_num, c[1000000][12];

int price()
{
	int ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		ret += (v[i] * pow(10, v.size() - i - 1));//뒤에서부터 10씩
	}
	return ret;
}
void dfs(int cnt)
{
	if (cnt >= N) {
		max_num = max(max_num, price());
		return;
	}

	//중복체크
	if (c[price()][cnt]) 
		return;   
	c[price()][cnt] = 1;

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			swap(v[i], v[j]);
			dfs(cnt + 1);
			swap(v[i], v[j]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> init_num >> N;
		for (int i = 0; i < init_num.size(); i++)
		{
			v.push_back(init_num[i] - '0');
		}
		dfs(0);
		cout << "#" << test_case << " " << max_num << "\n";
		max_num = 0;
		v.clear();
	}
}