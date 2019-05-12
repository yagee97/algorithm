#include <iostream>

using namespace std;
int n, result = 1;

int main()
{
	cin >> n;

	while (n > 0)
	{
		result = result * n;
		n--;
	}
	cout << result;
}