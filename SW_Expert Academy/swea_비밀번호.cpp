#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
int N;
vector<char> v;
bool flag;

int main(void)
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		flag = true;
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			char tmp;
			scanf("%1c", &tmp);
			v.push_back(tmp);
		}

		while (1) {
			if (flag == false)
				break;
			flag = false;

			for (int i = 1; i < v.size(); i++) {
				if (v[i - 1] == v[i]) {
					v.erase(v.begin() + i - 1, v.begin() + i + 1);
					flag = true;
				}
			}
		}
		printf("#%d ", test_case);
		for (int i = 0; i < v.size(); i++) {
			printf("%c", v[i]);
		}
		printf("\n");
		v.clear();
	}
}