#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visit[201][201][201];
int ma, mb, mc;
void bfs(int a, int b, int c) {
	if (a > 0) {
		//a¸¦ b¿¡ º×´Â´Ù.
		if (a > mb - b) {
			int temp = a - (mb - b);
			if (visit[temp][mb][c] == 0) {
				visit[temp][mb][c] = 1;
				bfs(temp, mb, c);
			}

		}
		else {
			if (visit[0][b + a][c] == 0) {
				visit[0][b + a][c] = 1;
				bfs(0, b + a, c);
			}
		}
		//a¸¦ c¿¡ º×´Â´Ù.
		if (a > mc - c) {
			int temp = a - (mc - c);
			if (visit[temp][b][mc] == 0) {
				visit[temp][b][mc] = 1;
				bfs(temp, b, mc);
			}

		}
		else {
			if (visit[0][b][c + a] == 0) {
				visit[0][b][c + a] = 1;
				bfs(0, b, c + a);
			}

		}
	}
	if (b > 0) {
		//b¸¦ a¿¡ º×´Â´Ù.
		if (b> ma - a) {
			int temp = b - (ma - a);
			if (visit[ma][temp][c] == 0) {
				visit[ma][temp][c] = 1;
				bfs(ma, temp, c);
			}

		}
		else {
			if (visit[b + a][0][c] == 0) {
				visit[a + b][0][c] = 1;
				bfs(b + a, 0, c);
			}



		}
		//b¸¦ c¿¡º×´Â´Ù.

		if (b > mc - c) {
			int temp = b - (mc - c);
			if (visit[a][temp][mc] == 0) {
				visit[a][temp][mc] = 1;
				bfs(a, temp, mc);
			}

		}
		else {
			if (visit[a][0][c + b] == 0) {
				visit[a][0][c + b] = 1;
				bfs(a, 0, c + b);
			}



		}
	}
	if (c > 0) {
		//c¸¦ a¿¡ º×´Â´Ù.
		if (c> ma - a) {
			int temp = c - (ma - a);
			if (visit[ma][b][temp] == 0) {
				visit[ma][b][temp] = 1;
				bfs(ma, b, temp);
			}

		}
		else {
			if (visit[a + c][b][0] == 0) {
				visit[a + c][b][0] = 1;
				bfs(c + a, b, 0);

			}

		}
		//c¸¦ b¿¡ º×´Â´Ù.
		if (c > mb - b) {

			int temp = c - (mb - b);
			if (visit[a][mb][temp] == 0) {
				visit[a][mb][temp] = 1;
				bfs(a, mb, temp);
			}
		}
		else {
			if (visit[a][b + c][0] == 0) {
				visit[a][c + b][0] = 1;
				bfs(a, c + b, 0);
			}
		}
	}
}
int  main() {

	scanf("%d%d%d", &ma, &mb, &mc);
	bfs(0, 0, mc);
	vector<int> result;
	for (int i = 0; i, i <= mb; i++) {
		for (int j = 0; j <= mc; j++) {
			if (visit[0][i][j] == 1)
				result.push_back(j);
		}
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}

}