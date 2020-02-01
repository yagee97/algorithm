import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

//새로운 불면증 치료법
public class swea_1288 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int K = 0;
			int cnt = 0;
			int[] freq = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
			while(true) {
				if(check(freq))
					break;
				K += N;
				count(K, freq);
				cnt++;
			}
			System.out.println("#"+tc+" "+K);
		}
	}
	
	static void count(int n, int[] freq) {
		
		while(n > 0) {
			int tmp = n % 10;
			freq[tmp]++;
			n /= 10;
		}
	}

	static boolean check(int[] freq) {
		for (int i = 0; i < freq.length; i++) {
			if(freq[i] == -1)
				return false;
		}
		return true;
	}
}
