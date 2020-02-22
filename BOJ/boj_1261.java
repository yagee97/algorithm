import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//알고스팟
public class boj_1261 {
	static class Pos {
		int x;
		int y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N, M;
	static int[][] map;
	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static boolean[][] check;
	static int[][] dis;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		M = sc.nextInt();
		N = sc.nextInt();
		map = new int[N][M];
		check = new boolean[N][M];
		dis = new int[N][M];

		for(int i = 0;i<N;i++) {
			for(int j = 0;j<M;j++) {
				dis[i][j] = 987654321;
			}
		}
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}
		dis[0][0] = 0;
		bfs(0, 0);

		System.out.println(dis[N - 1][M - 1]);
	}

	static void bfs(int x, int y) {
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(x, y));
		check[x][y] = true;
		while (!q.isEmpty()) {
			Pos p = q.poll();

			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				if (dis[nx][ny] > dis[p.x][p.y] + map[nx][ny]) {
					dis[nx][ny] = dis[p.x][p.y] + map[nx][ny];
					q.add(new Pos(nx, ny));
				}
			}
		}
	}
}
