#include <iostream>
#include <vector>
using namespace std;

int map[101][101], cnt, min_num;
vector<int> point;

void calculation(int y, int x) {
	cnt++;
	if (y == 99) //마지막줄
		return;

	map[y][x] = 0;

	//알고리즘에서 x,y 개념 헷갈리지 말기ㅣ
	if (x != 0 && map[y][x - 1])//왼쪽이면 이동해서 또 계산
		calculation(y, x - 1);
	else if (x != 99 && map[y][x + 1]) //오른쪽이면.
		calculation(y, x + 1);
	else
		calculation(y + 1, x); //아래

	map[y][x] = 1; //다시 1로. 다른 곳에서 출발했을 때도 여기 지나갈 수 있어야 하기 때문,

}
int solution() {
	for (int i = 0; i < 100; i++) {
		if (map[0][i] == 1) //출발점
		{
			cnt = 0;
			calculation(0, i);
			if (cnt > min_num)
				continue;
			else if (cnt < min_num) {//지금점에서 cnt가 제일 낮으면
				point.clear(); //최소라고 생각했던 출발점 다 지움
				min_num = cnt;
				point.push_back(i);//x좌표
			}
			else point.push_back(i);//여전히 최소가 유지라면, 추가
		}
	}
	return point[point.size() - 1];//여러개 중에 제일 큰거
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);//이거 효과 짱이다
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