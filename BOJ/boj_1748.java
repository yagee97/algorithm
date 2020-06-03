import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_1748 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N = br.readLine();
		int num = Integer.parseInt(N);
		int len = N.length();

		long dp[] = new long[10];

		dp[1] = 9;
		
		for (int i = 2; i <= 9; i++) {
			dp[i] = (((long) (Math.pow(10, i))-1) - ((long) (Math.pow(10, i-1))) + 1)*i;
		}
		int tmp = 0;
		for (int i = 1; i < len; i++) {
			tmp += dp[i];
		}
		tmp += (num - (int)(Math.pow(10, len-1)) +1)*len;
		
		System.out.println(tmp);

	}
}
