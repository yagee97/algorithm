
#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;

int a, b;

int cal(int now)
{

	if (now == 1)return a;

	return (a * cal(now - 1));

}

int main()

{

	int T; int t;

	T = 10;
	while (T--)

	{
		cin >> t;
		cin >> a >> b;
		cout << "#" << t << " " << cal(b) << endl;
	}

	return 0;

}