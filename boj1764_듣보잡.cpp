#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string name1[500001], name2;
string temp[500001];
int n, m,cnt=0;
vector<string> v;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name1[i];
	}

	sort(name1, name1 + n);
	for (int i = 0; i < m; i++) {
		cin >> name2;
		if (binary_search(name1, name1 + n, name2)) {
			v.push_back(name2);
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
	
}