import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 다항식 계산
public class swea_9659시간초과 {
	static int N, M;
	static int[] t, a, b;
	static long[] x;

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
			x = new long[N];
			for (int i = 2; i <= N; i++) {
				st = new StringTokenizer(br.readLine());
				t[i] = Integer.parseInt(st.nextToken());
				a[i] = Integer.parseInt(st.nextToken());
				b[i] = Integer.parseInt(st.nextToken());
			}

			M = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());

			for (int i = 0; i < M; i++) {
				x[i] = Integer.parseInt(st.nextToken());
				long ans = func(N, x[i]);
				sb.append(ans % 998244353 + " ");
			}
			System.out.println(sb.toString());
		}
	}

	private static long func(int N, long x) {
		if (N == 0)
			return 1;
		else if (N == 11)
			return x;
		else if (N >= 2) {
			if (t[N] == 1) {
				return func(a[N], x) + func(b[N], x);
			} else if (t[N] == 2)
				return a[N] * func(b[N], x);
			else if (t[N] == 3)
				return func(a[N], x) * func(b[N], x);
		}
		return x;
	}
}
