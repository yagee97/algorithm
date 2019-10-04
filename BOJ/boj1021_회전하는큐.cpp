#include <iostream>
#include <queue>

using namespace std;
int n, m, cnt = 0;
int map[51];
deque<int> q;
deque<int>::iterator it;
int idx = 0;

void second(int left)
{
	for (int i = 1; i <= left; i++)
	{
		int x = q.front();
		q.pop_front();
		q.push_back(x);
		cnt++;
	}
	q.pop_front();
}

void third(int right)
{
	for (int i = 1; i <= right; i++) {
		int x = q.back();
		q.pop_back();
		q.push_front(x);
		cnt++;
	}
	q.pop_front();
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		idx = 1;
		for (it = q.begin(); it < q.end(); it++) {
			if (*it == num) {//위치찾기
				break;
			}
			idx++;
		}


		int left = idx - 1;
		int right = q.size() + 1 - idx;
		if (left < right) {
			second(left);
		}
		else {
			third(right);
		}
	}
	printf("%d", cnt);
}