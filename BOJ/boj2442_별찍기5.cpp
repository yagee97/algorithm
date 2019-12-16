#include <cstdio>
#include <iostream>

using namespace std;
int num;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < num - i; j++) {
			cout << " ";
		}
		for (int k = 0; k < i * 2 - 1; k++) {
			cout << "*";
		}
		cout << "\n";
	}

}