import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

//안전영역
public class boj2468 {
	static int high = 0, N,cnt;
	static int[][] map;
	static boolean[][] visit;

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, -1, 0, 1 };
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int max = 0;
		N = sc.nextInt();
		map = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
				if (high < map[i][j])
					high = map[i][j];
			}
		}

		while (high-- > 0) {
			cnt = 0;
			visit = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// dfs
					if (!visit[i][j] && map[i][j] > high) {
						dfs(i, j, high);
						cnt++;
					}
				}
			}
			max = Math.max(max, cnt);
		}
		System.out.println(max);
	}

	static void dfs(int x, int y, int high) {

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (!visit[nx][ny] && map[nx][ny] > high) {
				visit[nx][ny] = true;
				dfs(nx, ny, high);
			}
		}
	}
}
