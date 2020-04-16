import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj2579 {

	static int score[] = new int[301];
	static int dp[] = new int[301];

	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		for (int i = 1; i <= N; i++) {
			score[i] = Integer.parseInt(br.readLine());
		}

		dp[1] = score[1];
		dp[2] = score[2] + score[1];
		dp[3] = score[3] + Math.max(score[1], score[2]);
		for (int i = 4; i <= N; i++) {
			dp[i] = score[i] + Math.max(dp[i - 2], dp[i - 3] + score[i - 1]);
		}

		System.out.println(dp[N]);
	}

}