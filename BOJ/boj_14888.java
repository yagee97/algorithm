import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

//연산자 끼워넣기
public class boj_14888 {
	static int N, arr[];
	static int[] op;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		N = Integer.parseInt(br.readLine());

		arr = new int[N];
		op = new int[4];

		// 피연산자
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		// 연산자
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 4; i++)
			op[i] = Integer.parseInt(st.nextToken());
		
		solve(1, arr[0]);
		System.out.println(max);
		System.out.println(min);

	}

	static int max = Integer.MIN_VALUE;
	static int min = Integer.MAX_VALUE;

	private static void solve(int idx, int sum) {
		if (idx == N) {
			// 최대최소 구하기
			max = Math.max(max, sum);
			min = Math.min(min, sum);
			return;
		}

		// 연산자 하나써보기
		if (op[0] > 0) {
			op[0]--;
			solve(idx + 1, sum + arr[idx]);
			op[0]++;
		}
		if (op[1] > 0) {
			op[1]--;
			solve(idx + 1, sum - arr[idx]);
			op[1]++;
		}
		if (op[2] > 0) {
			op[2]--;
			solve(idx + 1, sum * arr[idx]);
			op[2]++;
		}
		if (op[3] > 0) {
			op[3]--;
			solve(idx + 1, sum / arr[idx]);
			op[3]++;
		}

	}
}
