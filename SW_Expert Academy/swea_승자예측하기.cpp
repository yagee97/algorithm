#include <iostream>
#include <algorithm>
using namespace std;

int T;
long long N, level, x = 1;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;

		if (N == 1) {
			cout << "#" << test_case << " Bob\n";
			continue;
		}
		else if (N == 2 || N == 3) {
			cout << "#" << test_case << " Alice\n";
			continue;
		}
		else
		{
			// N 층수
			level = N;
			x = 1;
			int depth = 0;
			while (level > 1)
			{
				depth++;
				level /= 2;
			}
			// depth는 둘이서 총 몇번 번갈아가느냐!
			if (depth % 2 == 0) //depth 가 짝수
			{
				for (int i = 0; i < depth; i++)
				{
					if (i % 2 == 0) //bob은 크게
						x = 2 * x + 1;

					else x = 2 * x;//alice는 작게

					if (i == depth - 1 && x <= N)
						//depth-1은 alice, x가 N까지 아직이면 bob이 이김.
					{
						cout << "#" << test_case << " Bob\n";
						break;
					}
					else if (i == depth - 1 && x > N)
						//depth가 짝수인데 x가 N을 넘었으면 bob이 뭘 고르던 짐
					{
						cout << "#" << test_case << " Alice\n";
						break;
					}
				}
			}
			else//depth가 홀수
			{
				for (int i = 0; i < depth; i++)
				{
					if (i % 2 == 0) //bob은 작게
						x = 2 * x;
					else
						x = 2 * x + 1;//alice는 크게. 

					if (i == depth - 1 && x <= N)
					{
						cout << "#" << test_case << " Alice\n";
						break;
					}
					else if (i == depth - 1 && x > N)
					{
						cout << "#" << test_case << " Bob\n";
						break;
					}
				}
			}

		}
	}

	return 0;
}