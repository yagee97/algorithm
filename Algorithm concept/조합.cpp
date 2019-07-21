/*#include <cstdio>
#include <iostream>

#define MAX 5
using namespace std;

int arr[MAX];
bool select[MAX];

void print() {

	for (int i = 0; i < MAX; i++) {
		if (select[i] == true) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;

}
void dfs(int Idx, int cnt)
{
	if (cnt == 3)
	{
		print();
		return;
	}
	for (int i = Idx; i < MAX; i++) {
		if (select[i] == true)
			continue;
		select[i] = true;
		dfs(i, cnt + 1);
		select[i] = false;
	}
}

int main()
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	dfs(0, 0);
}*/