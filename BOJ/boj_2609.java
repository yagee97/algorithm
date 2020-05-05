import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 최대공약수와 최소공배수
public class boj_2609 {
	static int N1, N2;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		StringBuilder sb = new StringBuilder();
		
		N1 = Integer.parseInt(st.nextToken());
		N2 = Integer.parseInt(st.nextToken());
		int gcd = GCD(N1, N2);
		int lcm = LCM(N1, N2, gcd);
		sb.append(gcd).append("\n").append(lcm);
		System.out.println(sb.toString());

	}

	// 최대공약수
	private static int GCD(int N1, int N2) {

		while (N1 % N2 != 0) {
			int tmp = N2;
			N2 = N1 % N2;
			N1 = tmp;
		}
		return N2;
	}

	// 최소공배수
	private static int LCM(int N1, int N2, int gcd) {

		return (N1 * N2) / gcd;
	}

}
