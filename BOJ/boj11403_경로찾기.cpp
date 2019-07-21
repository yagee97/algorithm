#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;
int n;
vector<int> v[101];
int result[101][101];
bool visit[101];
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				v[i].push_back(j);
			}
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		memset(visit, false, sizeof(visit));
		q.push(i);

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (int i = 0; i < v[now].size(); i++)
			{
				int next = v[now][i];
				if (!visit[next])
				{
					visit[next] = true;
					q.push(next);

				}
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (visit[j])
			{
				result[i][j] = 1;
			}
			else
			{
				result[i][j] = 0;
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}





	return 0;
}