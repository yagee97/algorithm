import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 1,2,3 더하기
public class boj_9095 {
	static int N;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			ans = 0;
			N = Integer.parseInt(br.readLine());
			solve(0, 0);
			System.out.println(ans);
		}
	}

	static int ans = 0;

	private static void solve(int idx, int sum) {
		if (sum == N) {
			ans++;
			return;
		}
		if (sum > N)
			return;

		solve(idx + 1, sum + 1);
		solve(idx + 1, sum + 2);
		solve(idx + 1, sum + 3);

	}
}
