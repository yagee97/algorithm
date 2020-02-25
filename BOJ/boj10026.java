import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj10026 {

	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N;
	static char[][] map;
	static boolean[][] check;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		map = new char[N][N];
		check = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!check[i][j]) {
					bfs(i, j, 1);
					ret1++;
				}
			}
		}
		check = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!check[i][j]) {
					bfs(i, j, 2);
					ret2++;
				}
			}
		}

		System.out.println(ret1+ " "+ ret2);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int ret1 = 0, ret2 = 0;

	static void bfs(int x, int y, int type) {
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(x, y));
		check[x][y] = true;

		while (!q.isEmpty()) {
			Pos p = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (type == 1) {
					if (!check[nx][ny] && map[nx][ny] == map[p.x][p.y]) {
						q.add(new Pos(nx, ny));
						check[nx][ny] = true;
					}
				} else if (type == 2) {
					if (!check[nx][ny] && (map[p.x][p.y] == 'R' || map[p.x][p.y] == 'G')) {
						if ((map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
							q.add(new Pos(nx, ny));
							check[nx][ny] = true;
						}
					} else if (!check[nx][ny] && map[p.x][p.y] == 'B') {
						if (map[nx][ny] == map[p.x][p.y]) {
							q.add(new Pos(nx, ny));
							check[nx][ny] = true;
						}
					}
				}
			}
		}
	}
}
