import java.util.Scanner;

// 1로 만들기
public class boj_1463 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] dp = new int[1000001];

		for (int i = 2; i < N + 1; i++) {
			// 1 빼는 법
			dp[i] = dp[i - 1] + 1;
			// 2로 나누는 방법
			if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
				dp[i] = dp[i / 2] + 1;

			}
			// 3으로 나누는 방법
			if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
				dp[i] = dp[i / 3] + 1;

			}
		}
		System.out.println(dp[N]);
	}
}
