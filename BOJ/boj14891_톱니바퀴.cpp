#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int k, rot_num, rot_dir;
vector<int> gear[5];
int turn[5];

void turn_chk(int num, int dir)
{
	char copy[10];

	for (int i = 0; i <= 7; i++) {
		copy[i] = gear[num][i];
	}

	if (dir == 1)//시계방향
	{
		gear[num][0] = copy[7];
		for (int i = 1; i <= 7; i++) {
			gear[num][i] = copy[i - 1];
		}

	}
	else if (dir == -1) {//반시계
		gear[num][7] = copy[0];
		for (int i = 0; i <= 6; i++) {
			gear[num][i] = copy[i + 1];
		}
	}
}

void solve(int num, int dir)
{
	turn[num] = dir; // 회전해야하는 톱니바쿠ㅣ에 회전방향 넣기

	for (int i = num; i < 4; i++) {
		if (gear[i][2] != gear[i + 1][6]) {

			turn[i + 1] = turn[i] * -1;
			//현재 회전한 톱니랑 다른 방향 저장

		}
		else
			break;
	}

	for (int i = num; i > 1; i--) {
		if (gear[i][6] != gear[i - 1][2]) {
			turn[i - 1] = turn[i] * -1;
		}
		else
			break;
		}
	
}



int main()
{
	for (int i = 1; i <= 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			gear[i].push_back(s[j] - '0');
	}


	cin >> k;
	for (int i = 0; i < k; i++) {

		for (int j = 1; j <= 4; j++)
		{
			turn[j] = 0;
		}

		cin >> rot_num >> rot_dir;

		solve(rot_num, rot_dir);

		for (int j = 1; j <= 4; j++) {
			if (turn[j] != 0) {
				turn_chk(j, turn[j]);
			}
		}
	}

	int score = 0;
	if (gear[1][0] == 1)
		score += 1;
	if (gear[2][0] == 1)
		score += 2;
	if (gear[3][0] == 1)
		score += 4;
	if (gear[4][0] == 1)
		score += 8;
	cout << score << "\n";
	cout << "\n";

}