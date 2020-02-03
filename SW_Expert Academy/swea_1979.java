import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class swea_1979 {
	static int[][] map;
	static int N, K;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			K = sc.nextInt();
			map = new int[N + 1][N + 1];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int cnt = 0;
			int ret = 0;

			// 가로
			for (int i = 0; i < N; i++) {
				int j = 0;
				cnt = 0;
				while (true) {
					if (map[i][j] == 1) {
						cnt++;
						j++;
					} else if (map[i][j] == 0) {
						if (cnt == K) {
							ret++;
						}
						cnt = 0;
						j++;
					}
					if (j == N) {
						if(cnt == K) ret++;
						break;
					}
				}
			}
			//세로
			for (int i = 0; i < N; i++) {
				int j = 0;
				cnt = 0;
				while (true) {
					if (map[j][i] == 1) {
						cnt++;
						j++;
					} else if (map[j][i] == 0) {
						if (cnt == K) {
							ret++;
						}
						cnt = 0;
						j++;
					}
					if (j == N) {
						if(cnt == K) ret++;
						break;
					}
				}
			}
			System.out.println("#" + tc + " " + ret);
		}
	}
}
