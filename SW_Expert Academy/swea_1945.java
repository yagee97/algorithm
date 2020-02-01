import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class swea_1945 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] arr = { 2, 3, 5, 7, 11 };

		for (int tc = 1; tc <= T; tc++) {
			int n = sc.nextInt();
			int a = 0, b = 0, c = 0, d = 0, e = 0;
			while(n%2 == 0) {
				n /= 2;
				a++;
			}
			while(n%3 == 0) {
				n/=3;
				b++;
			}
			while(n%5==0) {
				n/=5; c++;
			}
			while(n%7==0) {
				n/=7; d++;
			}
			while(n%11==0) {
				n/=11; e++;
			}
			System.out.format("#%d %d %d %d %d %d\n",tc, a,b,c,d,e);
		}

	}
}
