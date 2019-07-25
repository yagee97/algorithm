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
			// N ����
			level = N;
			x = 1;
			int depth = 0;
			while (level > 1)
			{
				depth++;
				level /= 2;
			}
			// depth�� ���̼� �� ��� �����ư�����!
			if (depth % 2 == 0) //depth �� ¦��
			{
				for (int i = 0; i < depth; i++)
				{
					if (i % 2 == 0) //bob�� ũ��
						x = 2 * x + 1;

					else x = 2 * x;//alice�� �۰�

					if (i == depth - 1 && x <= N)
						//depth-1�� alice, x�� N���� �����̸� bob�� �̱�.
					{
						cout << "#" << test_case << " Bob\n";
						break;
					}
					else if (i == depth - 1 && x > N)
						//depth�� ¦���ε� x�� N�� �Ѿ����� bob�� �� ���� ��
					{
						cout << "#" << test_case << " Alice\n";
						break;
					}
				}
			}
			else//depth�� Ȧ��
			{
				for (int i = 0; i < depth; i++)
				{
					if (i % 2 == 0) //bob�� �۰�
						x = 2 * x;
					else
						x = 2 * x + 1;//alice�� ũ��. 

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