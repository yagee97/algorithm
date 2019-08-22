#include <string>
#include <iostream>

using namespace std;
int T, result=0;

int main(void)
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		string memory;
		cin >> memory;
		char flag = '0';
		for (int i = 0; i < memory.length(); i++) {
			if (memory[i] == flag) continue;
			else {
				if (flag == '0')
					flag = '1';
				else flag = '0';
				result++;
			}
		}
		printf("#%d %d\n", test_case, result);
		result = 0;
	}

}