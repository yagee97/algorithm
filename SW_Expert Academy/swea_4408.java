import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class swea_4408 {
	static int[] corridor;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			corridor = new int[201];
			int max = 0;

			for (int i = 0; i < N; i++) {
				int start = sc.nextInt();
				int end = sc.nextInt();
				if (start == 1) {
					start = 1;
				} else {
					if (start % 2 == 0) {
						start /= 2;
					} else if (start % 2 != 0) {
						start = start / 2 + 1;
					}
				}
				if (end == 1) {
					end = 1;
				} else {
					if (end % 2 == 0) {
						end = end / 2;
					} else if (end % 2 != 0) {
						end = end / 2 + 1;
					}
				}
				
				if(start > end) {
					int tmp = start;
					start = end;
					end = tmp;
				}
				for (int j = start; j <= end; j++) {
					corridor[j]++;
					if (max < corridor[j])
						max = corridor[j];
				}
			}
			System.out.println("#" + tc + " " + max);
		}
	}
}
