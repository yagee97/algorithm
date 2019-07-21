#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int L, a, b, c, d;
	cin >> L >> a >> b >> c >> d;
	int korean, math, day;

	korean = a / c;
	if ((a % c) != 0) {
		korean++;
	}
	
	math = b / d;
	if ((b % d) != 0) {
		math++;
	}
	day = max(korean, math);

	cout << L - day;

}