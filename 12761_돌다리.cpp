#include <cstdio>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	int a, b, n, m;
	int next=0,cnt=0;
	int position = 0, s=0;
	 bool visit[100001] = {false, };

	scanf_s("%d%d%d%d", &a, &b, &n, &m);

	q.push(n);
	visit[n] = true;

	while (!q.empty())
	{
		s = q.size();
		while (s>0) {

			position = q.front();
			q.pop();

			int move[8] = { 1,-1,a,-a,b,-b,a,b };
			if (position == m)
			{
				printf("%d", cnt);
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				if (i < 6)
					next = move[i] + position;
				else
					next = move[i] * position;

				if (next <= 100000 && next >= 0 && visit[next] == false) {
					visit[next] = true;
					q.push(next);
				}
			}
			s--;
		}
		cnt++;
	}


}