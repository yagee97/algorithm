#include <iostream>

using namespace std;
int t,n;
int map[11];
int cnt = 0;

bool check(int i)
{
	int k = 1;
	bool flag = true;

	while (k < i && flag)
	{
		if (map[i] == map[k] || abs(map[i] - map[k]) == i - k)
			flag = false;
		k++;
	}
	return flag;
}

void queens(int i)
{
	if (check(i))
	{
		if (i == n)//n까지 갔으면 완성된 체스판이므로
			cnt++;//경우의 수 세기
		else
			for (int j = 1; j <= n; j++) {
				//i+1에 퀸을 하나씩 놓아봄
				map[i + 1] = j;
				queens(i + 1);
			}
	}
}

int main()
{
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		cnt = 0;
		cin >> n;
		queens(0);
		cout << "#" << test_case << " " << cnt << endl;
	}
}