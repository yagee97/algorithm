#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int roomNum;
	int q, max_set = 0;
	int arr[10] = { 0, };

	cin >> roomNum;
	q = roomNum;

	while (1) {
		arr[q % 10]++;
		if (q / 10 == 0) break;
		q /= 10;
	}

	double tmp = 0;
	tmp = round(double(arr[6] + arr[9]) / 2);
	arr[6] = tmp;
	arr[9] = tmp;

	max_set = *max_element(arr, arr + 10);
	cout << max_set;
}