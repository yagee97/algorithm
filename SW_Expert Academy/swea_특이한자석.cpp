#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<int> magnetic[5];
int num, dir;
int turn_mag[5];

void rotate(int num, int dir)
{
	int copy[10];
	for (int i = 0; i < 8; i++) {
		copy[i] = magnetic[num][i];
	}

	if (dir == -1)//¹Ý½Ã°è
	{
		magnetic[num][7] = copy[0];
		for (int i = 0; i < 7; i++) {
			magnetic[num][i] = copy[i + 1];
		}
		
	}
	else if(dir == 1)
	{
		magnetic[num][0] = copy[7];
		for (int i = 1; i <= 7; i++) {
			magnetic[num][i] = copy[i - 1];
		}
		
	}
}

void check_rot(int num, int dir)
{
	turn_mag[num] = dir;

	for (int i = num; i < 4; i++) {
		if (magnetic[i][2] != magnetic[i + 1][6])
		{
			turn_mag[i + 1] = turn_mag[i] * -1;
		}
		else
			break;
	}

	for (int i = num; i > 1; i--) {
		if (magnetic[i][6] != magnetic[i - 1][2])
		{
			turn_mag[i - 1] = turn_mag[i] * -1;
		}
		else
			break;
	}

}

int main()
{
	int T, k;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> k;
		for (int i = 1; i <= 4; i++) {
			magnetic[i].clear();
		}
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				int tmp;
				cin >> tmp;
				magnetic[i].push_back(tmp);
			}
			
		}

		for (int i = 0; i < k; i++) {
			for (int j = 1; j <= 4; j++)
			{
				turn_mag[j] = 0;
			}
			cin >> num >> dir;

			check_rot(num, dir);

			for (int k = 1; k <= 4; k++) {
				if (turn_mag[k] != 0) {
					rotate(k, turn_mag[k]);
				}
			}
		}

		int ans = 0; 
		if (magnetic[1][0] == 1)
			ans += 1;
		if (magnetic[2][0] == 1)
			ans += 2;
		if (magnetic[3][0] == 1)
			ans += 4;
		if (magnetic[4][0] == 1)
			ans += 8;

		cout << "#" << test_case << " "<< ans << "\n";
	}

}
