import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_1248 {
	static int N;
	static char[][] S;
	static int[] ans, sum;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		S = new char[N + 1][N + 1];
		ans = new int[N + 1];
		sum = new int[N + 1];
		String str = br.readLine();
		int strIdx = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				if (str.charAt(strIdx) == '-') {
					S[i][j] = '-';
				}
				if (str.charAt(strIdx) == '+') {
					S[i][j] = '+';
				}
				if (str.charAt(strIdx) == '0') {
					S[i][j] = '0';
				}
				strIdx++;
			}
		}

		dfs(1);
	}

	private static boolean check(int idx) {
		for (int i = 1; i <= idx; i++) {
			char c = S[i][idx];
			//구간합
			int ret = sum[idx] - sum[i - 1];
			if (c == '+' && ret <= 0)
				return false;
			if (c == '-' && ret >= 0)
				return false;
			if (c == '0' && ret != 0)
				return false;
		}
		return true;
	}

	private static void dfs(int idx) {
		if (idx == N+1) {
			for (int i = 1; i <= N; i++) {
				System.out.print(ans[i] + " ");
			}
			System.exit(0);
		}

		for (int i = 0; i <= 20; i++) {
			ans[idx] = i-10;// 값 선택
			sum[idx] = sum[idx - 1] + ans[idx];
			if (check(idx))
				dfs(idx + 1);
			ans[idx] = sum[idx] = 0;
		}
	}
}
