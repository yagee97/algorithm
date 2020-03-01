import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class 수영장 {
	static int plan[];
	static int ticket[];

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + tc + " ");
			ticket = new int[4];
			for (int i = 0; i < 4; i++)
				ticket[i] = sc.nextInt();

			plan = new int[12];
			for (int i = 0; i < 12; i++)
				plan[i] = sc.nextInt();

			min = Integer.MAX_VALUE;
			solve(0, 0);
			int ret = 0;
			if (min > ticket[3])
				ret = ticket[3];
			else
				ret = min;
			sb.append(ret);
			System.out.println(sb.toString());
		}
	}

	static int min = 0;

	static void solve(int idx, int sum) {
		if (idx >= 12) {
			min = Math.min(min, sum);
			return;
		}

		if (plan[idx] == 0) {
			solve(idx + 1, sum);
		} else {
			// 1일권
			solve(idx + 1, sum + (plan[idx] * ticket[0]));
			// 한달
			solve(idx + 1, sum + ticket[1]);
			// 세달
			solve(idx + 3, sum + ticket[2]);
		}
	}
}
