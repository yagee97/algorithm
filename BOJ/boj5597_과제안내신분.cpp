#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> notSubmit;
int main()
{
	int n, student[31] = {0,};
	for (int i = 0; i < 28; i++) {
		scanf("%d", &n);
		student[n] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (student[i] == 0) {
			notSubmit.push_back(i);
		}
	}

	sort(notSubmit.begin(), notSubmit.end());

	for (int i = 0; i < notSubmit.size(); i++) {
		printf("%d\n", notSubmit[i]);
	}

}