#include <iostream>
#include <vector>
using namespace std;

int map[101][101], cnt, min_num;
vector<int> point;

void calculation(int y, int x) {
	cnt++;
	if (y == 99) //��������
		return;

	map[y][x] = 0;

	//�˰��򿡼� x,y ���� �򰥸��� �����
	if (x != 0 && map[y][x - 1])//�����̸� �̵��ؼ� �� ���
		calculation(y, x - 1);
	else if (x != 99 && map[y][x + 1]) //�������̸�.
		calculation(y, x + 1);
	else
		calculation(y + 1, x); //�Ʒ�

	map[y][x] = 1; //�ٽ� 1��. �ٸ� ������ ������� ���� ���� ������ �� �־�� �ϱ� ����,

}
int solution() {
	for (int i = 0; i < 100; i++) {
		if (map[0][i] == 1) //�����
		{
			cnt = 0;
			calculation(0, i);
			if (cnt > min_num)
				continue;
			else if (cnt < min_num) {//���������� cnt�� ���� ������
				point.clear(); //�ּҶ�� �����ߴ� ����� �� ����
				min_num = cnt;
				point.push_back(i);//x��ǥ
			}
			else point.push_back(i);//������ �ּҰ� �������, �߰�
		}
	}
	return point[point.size() - 1];//������ �߿� ���� ū��
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);//�̰� ȿ�� ¯�̴�
	for (int test_case = 1; test_case <= 10; test_case++) {
		min_num = 99999999;
		int test;
		cin >> test;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> map[y][x];
			}
		}
		cout << "#" << test_case << ' ' << solution() << endl;
	}
}