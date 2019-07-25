#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		long long N;
		cin >> N;

		if (N <= 3LL)
		{
			if (N == 1LL) cout << "#" << test_case << " Bob\n";
			else cout << "#" << test_case << " Alice\n";
			continue;
		}
		else
		{
			// N�� ���� ���ϱ�
			long long num = N, x = 1LL;
			int depth = 0;
			while (num > 1LL)
			{
				depth++;
				num /= 2LL;
			}
			if (depth % 2 == 0) // depth�� ¦���� bob�� N/2 ���ϸ� ���� ���� ����.
			{
				for (int i = 0; i < depth; i++)
				{   // �ٸ������� �����ϴϱ� 2x+1 �Ϸ��� ����ϰ���.
					if (i % 2 == 0) x = 2 * x + 1LL;
					else x = 2 * x;
					if (i == depth - 1 && x <= N)
					{
						cout << "#" << test_case << " Bob\n";
						break;
					}
					else if (i == depth - 1 && x > N)
					{
						cout << "#" << test_case << " Alice\n";
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < depth; i++)
				{
					if (i % 2 == 0) x = 2 * x;
					else x = 2 * x + 1LL;
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