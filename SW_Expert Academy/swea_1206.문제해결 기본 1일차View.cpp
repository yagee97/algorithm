#include <iostream>
#include <cstring>

using namespace std;

int case_num;
int map[256][1002];
int num, cnt = 0;
int flag;
int main()
{
	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> case_num;
		cnt = 0;
		memset(map, 0, sizeof(map));
		flag = 0;

		for (int i = 0; i < case_num; i++) {
			cin >> num;
			for (int j = 0; j < num; j++) {
				map[j][i] = 1;//���μ��� �� ������
			}
		}

		for (int i = 0; i < 255; i++) {
			for (int j = 0; j < case_num;j++) {
				if (map[i][j] == 1) {
					flag = 0;
					for (int k = 1; k < 3; k++) {//���� �Ÿ� 2�ȿ� 1�� ������ flag 1�� �ٲ�
						if (map[i][j + k] == 1 || map[i][j - k] == 1) {
							flag = 1;
						}
					}
					if (flag == 0) {//flag 0�̸� ������ Ȯ�� ����
						cnt++;
					}
				}
			}
		}
		cout << "#" << test_case << " " << cnt << endl;
	}
}