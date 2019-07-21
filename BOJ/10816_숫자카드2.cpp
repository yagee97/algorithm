#include <cstdio>
#include <map>
using namespace std;

int n, m,num;

map<int, int> card;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		card[num]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num);
		printf("%d ", card[num]);

	}

}