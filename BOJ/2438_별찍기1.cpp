#include <cstdio>
#include <iostream>
using namespace std;
int num;
int main(void)
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}