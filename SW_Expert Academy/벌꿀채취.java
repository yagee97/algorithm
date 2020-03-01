import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class 벌꿀채취 {
	static int N, M, C;
	static int[][] map;
	static int[][] maxMap;

	public static void main(String[] args) throws FileNotFoundException {

		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + tc + " ");
			N = sc.nextInt();
			M = sc.nextInt();
			C = sc.nextInt();
			map = new int[N][N];
			maxMap = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j <= N - M; j++) {
					makeMax(i, j, 0, 0, 0);
				}
			}
			sb.append(solve());
			System.out.println(sb.toString());
		}
	}

	// 상태를 가지고 움직일때는 dfs
	static void makeMax(int i, int j, int cnt, int sum, int benefit) {

		if (sum > C)
			return;

		if (cnt == M) {
			if (maxMap[i][j - M] < benefit) {
				maxMap[i][j - M] = benefit;
			}
			return;
		}

		// 선택
		makeMax(i, j + 1, cnt + 1, sum + map[i][j], benefit + (map[i][j] * map[i][j]));
		// 선택x
		makeMax(i, j + 1, cnt + 1, sum, benefit);
	}

	static int solve() {
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				// 같은행
				for (int j2 = j + M; j2 < N - M; j2++) {
					int tmp = maxMap[i][j] + maxMap[i][j2];
					max = Math.max(tmp, max);
				}

				// 다음행
				for (int i2 = i + 1; i2 < N; i2++) {
					for (int j2 = 0; j2 <= N - M; j2++) {
						int tmp = maxMap[i][j] + maxMap[i2][j2];
						max = Math.max(tmp, max);
					}
				}
			}
		}
		return max;
	}
}
