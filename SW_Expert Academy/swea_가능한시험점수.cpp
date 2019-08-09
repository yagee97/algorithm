#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
int T, N;
int score[101];
bool c[10001];
vector<int> v;

int cal()
{
	c[0] = true;
	v.push_back(0);//0Á¡

	for (int i = 0; i < N; i++) {
		for (int j = (int)v.size() - 1; j >= 0; j--) {
			int now = v[j];
			int next = now + score[i];

			if (!c[next]) {
				v.push_back(next);
				c[next] = true;
			}
		}
	}

	return (int)v.size();

}

int main()
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &score[i]);
		}

		memset(c, false, sizeof(c));
		printf("#%d %d\n", test_case, cal());

		v.clear();
	}
}