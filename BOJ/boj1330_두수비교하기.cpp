#include <iostream>

using namespace std;
int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n1, n2, ret = 0;
	cin >> n1 >> n2;

	ret = n1 - n2;
	if (ret > 0)
		cout << ">";
	else if (ret < 0)
		cout << "<";
	else
		cout << "==";


}