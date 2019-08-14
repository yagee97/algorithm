#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;

int T,N;
double cost;
ll result, x[1001], y[1001], set[1001];

struct Edge {
	ll x, y, dis;
	bool operator < (const Edge &edge) 
		const { return dis < edge.dis; }
};

ll Find(ll x) {
	// �ڱⰡ root ���� x �ڽ��� ����
	if (set[x] == x) return x;
	// ��ͷ� root ��� ã��. 
	else return set[x] = Find(set[x]);
}

void Union(ll a, ll b) {
	// ū �׷쿡 ���� �׷� ����
	a = Find(a);
	b = Find(b);

	set[a] = b;
}

ll cal_dist(ll x1, ll y1, ll x2, ll y2) {
	ll x = abs(x1 - x2);
	ll y = abs(y1 - y2);
	ll ret = pow(x, 2) + pow(y, 2);
	// �������� �Ÿ��� ������ ���ؼ� ����ؾ��ϱ� ������
	// �׳� sqrt ���ϴ� �ɷ� ��ü��
	return ret;
}
vector<Edge> v;

int main(void)
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		result = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &x[i]);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &y[i]);
		}
		scanf("%lf", &cost);
		//�θ� ����
		for (int i = 1; i <= N; i++)
			set[i] = i;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				v.push_back({ i,j, cal_dist(x[i], y[i], x[j], y[j])});
			}
		}
		// ����� �������� ����
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			Edge e = v[i];
			ll x = Find(e.x);
			ll y = Find(e.y);
			ll c = e.dis;
			if (x != y) {
				Union(e.x, e.y);
				result += c; // ��� �� ���ϱ�
			}
		}
		printf("#%lld %.0lf\n", test_case, result*cost);
		v.clear();
	}
}