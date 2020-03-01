import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class 햄버거다이어트 {
	static class Info {
		int score;
		int kal;

		public Info(int score, int kal) {
			this.score = score;
			this.kal = kal;
		}
	}

	static int N, L;
	static ArrayList<Info> list;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + tc + " ");
			max = 0;
			N = sc.nextInt();
			L = sc.nextInt();
			list = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				int score = sc.nextInt();
				int kal = sc.nextInt();
				list.add(new Info(score, kal));
			}
			solve(0, 0, 0);
			sb.append(max);
			System.out.println(sb.toString());
		}
	}

	static int max = 0;
	static void solve(int idx, int s, int k) {
		if (k > L)
			return;
		if (idx == N) {
			max = Math.max(max, s);
			return;
		}

		solve(idx + 1, s + list.get(idx).score, k + list.get(idx).kal);
		solve(idx + 1, s, k);

	}
}
