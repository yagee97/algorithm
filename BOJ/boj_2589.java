import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//보물섬
public class boj_2589 {
	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int L, W;
	static int[][] map;
	static boolean[][] check;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		L = sc.nextInt();
		W = sc.nextInt();
		map = new int[L][W];
		check = new boolean[L][W];

		for (int i = 0; i < L; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
			}
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 'L')
					bfs(i, j);
			}
		}
		System.out.println(max);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int max = 0;

	static void bfs(int x, int y) {
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(x, y));
		int depth = 0;
		check = new boolean[L][W];

		check[x][y] = true;

		while (!q.isEmpty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				Pos p = q.poll();
				for (int j = 0; j < 4; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					if (nx < 0 || ny < 0 || nx >= L || ny >= W)
						continue;
					if (!check[nx][ny] && map[nx][ny] == 'L') {
						q.add(new Pos(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
			depth++;
		}
		if (max < depth - 1)
			max = depth - 1;
	}

}
