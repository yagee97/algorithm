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
	// 자기가 root 노드면 x 자신을 리턴
	if (set[x] == x) return x;
	// 재귀로 root 노드 찾음. 
	else return set[x] = Find(set[x]);
}

void Union(ll a, ll b) {
	// 큰 그룹에 작은 그룹 결합
	a = Find(a);
	b = Find(b);

	set[a] = b;
}

ll cal_dist(ll x1, ll y1, ll x2, ll y2) {
	ll x = abs(x1 - x2);
	ll y = abs(y1 - y2);
	ll ret = pow(x, 2) + pow(y, 2);
	// 마지막에 거리의 제곱을 구해서 계산해야하기 때문에
	// 그냥 sqrt 안하는 걸로 대체함
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
		//부모 설정
		for (int i = 1; i <= N; i++)
			set[i] = i;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				v.push_back({ i,j, cal_dist(x[i], y[i], x[j], y[j])});
			}
		}
		// 비용을 기준으로 정렬
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			Edge e = v[i];
			ll x = Find(e.x);
			ll y = Find(e.y);
			ll c = e.dis;
			if (x != y) {
				Union(e.x, e.y);
				result += c; // 비용 다 더하기
			}
		}
		printf("#%lld %.0lf\n", test_case, result*cost);
		v.clear();
	}
}