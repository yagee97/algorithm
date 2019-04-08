#include <iostream>

using namespace std;

int main()
{
	int n, vote, cute = 0,notCute = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> vote;
		if (vote == 1)
			cute++;
		if (vote == 0)
			notCute++;
	}

	if (cute > notCute)
		cout << "Junhee is cute!";
	else if (cute < notCute)
		cout << "Junhee is not cute!";
}