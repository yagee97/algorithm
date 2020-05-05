import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 최소공배수
public class boj_1934 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N1 = Integer.parseInt(st.nextToken());
			int N2 = Integer.parseInt(st.nextToken());
			
			int lcm = (N1 * N2)/GCD(N1,N2);
			System.out.println(lcm);
		}
		
	}
	private static int GCD(int N1, int N2) {
		if(N2 == 0) {
			return N1;
		}
		else {
			return GCD(N2, N1%N2);
		}
	}
}
