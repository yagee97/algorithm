import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea_4012 {
	static int N, min = Integer.MAX_VALUE;
	static int[][] S;
	static boolean[] teamA;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc).append(" ");
			min = Integer.MAX_VALUE;
			N = Integer.parseInt(br.readLine());
			S = new int[N][N];
			teamA = new boolean[N];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) {
					S[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			solve(0, 0);
			sb.append(min);
			System.out.println(sb.toString());
		}
	}

	//s_idx는 내가 고른 것들이기 때문에 꾸준히 1씩 증가시켜야하고,
	//idx는 N개중에 내가 고르고 있는 곳을 나타내는것이기 때문에 for문의 인자를 가져가야함
	private static void solve(int idx, int s_idx) {
		if (idx == N)
			return;
		if (s_idx == N / 2) {
			// 팀 시너지 계산
			int A = 0, B = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == j)
						continue;
					if (teamA[i]) {
						if (teamA[i] == teamA[j]) {
							A += S[i][j];
						}
					} else {
						if (teamA[i] == teamA[j]) {
							B += S[i][j];
						}
					}
				}
			}
			int diff = Math.abs(A - B);
			min = Math.min(min, diff);
			// 최소값 갱신
			return;
		}

		for (int i = idx; i < N; i++) {
			if (!teamA[i]) {
				teamA[i] = true;
				solve(i, s_idx + 1);
				teamA[i] = false;
			}
		}
	}
}
