#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >>  num;

	for (int i = num; i > 0; i--) {
		for (int j = 0; j < num - i; j++) {
			cout << " ";
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			cout << "*";
		}
		cout << "\n";
	}
}