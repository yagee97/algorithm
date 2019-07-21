#include <cstdio>
#include <algorithm>

using namespace std;

int n,Max=0;
int box[1001];
int dp[1001];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &box[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = 1; //���ڿ� �ּ� 1���� ���� �� �־!
		for (int j = 1; j <= i;j++)
		{
			if (box[i] > box[j])//�ڿ� ���ڰ� �� Ŀ�ߴ�
				dp[i] = max(dp[i], dp[j] + 1);
		}
		Max = max(Max, dp[i]);//�ִ����
	}
	printf("%d", Max);

	return 0;
}