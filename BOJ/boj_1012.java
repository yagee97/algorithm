import java.util.Arrays;
import java.util.Scanner;

public class boj_1012 {
	static int M, N, K;
	static int[][] map;
	static boolean[][] check;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			M = sc.nextInt();
			N = sc.nextInt();
			K = sc.nextInt();
			map = new int[N][M];
			check = new boolean[N][M];
			for (int i = 0; i < K; i++) {
				int n1 = sc.nextInt();
				int n2 = sc.nextInt();
				map[n2][n1] = 1;
			}
			int ret = 0;
			for(int i = 0;i<N;i++) {
				for(int j = 0;j<M;j++) {
					if(!check[i][j] && map[i][j] == 1) {
						dfs(i,j);
						ret++;
					}
				}
			}
			System.out.println(ret);
		}
	}

	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static void dfs(int x, int y) {

		check[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (!check[nx][ny] && map[nx][ny] == 1) {
				check[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
}
