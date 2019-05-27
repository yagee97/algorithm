#include <iostream>
using namespace std;
int t, D,H,M;
int cnt = 0;
int ret = 0;
int calTime(int d, int h,int m)
{
	int result;
	if (d != 0) {
		d = (d - 11) * 1440;
	}
	if (h != 0) {
		h = (h - 11) * 60;
	}
	if (m != 0) {
		m = (m - 11);
	}
	result = d + h + m;
	return result;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		cnt++;
		scanf("%d %d %d", &D, &H, &M);

		if (D == 11) {
			if (H < 11) {
				printf("#%d -1\n", cnt);
			}
			else if (H == 11) {
				if (M < 11)
					printf("#%d -1\n", cnt);
				else if (M == 11)
					printf("#%d 0\n", cnt);
				else {
					ret = calTime(0, 0, M);
					printf("#%d %d\n", cnt, ret);
				}
			}
		}

		if (D > 11) {
			ret = calTime(D, H, M);
			printf("#%d %d\n", cnt, ret);
		}	
	}
}