import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_9659 {
	static int N, M;
	static int[] t, a, b;
	static long[] ret;
	static final long MOD = 998244353;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			StringTokenizer st = null;
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc).append(" ");
			N = Integer.parseInt(br.readLine());
			t = new int[N + 2];
			a = new int[N + 2];
			b = new int[N + 2];
			ret = new long[N + 2];
			for (int i = 2; i <= N; i++) {
				st = new StringTokenizer(br.readLine());
				t[i] = Integer.parseInt(st.nextToken());
				a[i] = Integer.parseInt(st.nextToken());
				b[i] = Integer.parseInt(st.nextToken());
			}

			M = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++) {
				int num = Integer.parseInt(st.nextToken());
				ret[0] = 1;
				ret[1] = num; // f1(x) = x
				for (int j = 2; j <= N; j++) {
					if (t[j] == 1) {
						ret[j] = (ret[a[j]] + ret[b[j]]) % MOD;
					} else if (t[j] == 2)
						ret[j] = (a[j] * ret[b[j]]) % MOD;
					else if (t[j] == 3)
						ret[j] = (ret[a[j]] * ret[b[j]]) % MOD;
				}
				sb.append(ret[N]).append(" ");
			}
			System.out.println(sb.toString());
		}
	}
}