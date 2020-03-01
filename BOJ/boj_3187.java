import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj_3187 {
	static class Info {
		int x, y;

		public Info(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static int R, C;
	static char[][] map;
	static boolean[][] visit;
	static int kCnt = 0, vCnt = 0;
	static int totalK = 0, totalV = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		R = sc.nextInt();
		C = sc.nextInt();
		map = new char[R][C];
		visit = new boolean[R][C];

		for (int i = 0; i < R; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == 'v')
					totalV++;
				else if (map[i][j] == 'k')
					totalK++;
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!visit[i][j] && map[i][j] != '#') {
					bfs(i, j);
					if (vCnt >= kCnt) {
						if(totalK == 0)
							continue;
						totalK -= kCnt;
					} else if (vCnt < kCnt) {
						if(totalV == 0)
							continue;
						totalV -= vCnt;
					}
				}
			}
		}
		System.out.println(totalK+" "+ totalV);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static void bfs(int x, int y) {
		Queue<Info> q = new LinkedList<>();
		q.add(new Info(x, y));
		visit[x][y] = true;
		kCnt = 0;
		vCnt = 0;
		if(map[x][y] == 'v')
			vCnt++;
		else if(map[x][y] == 'k')
			kCnt++;

		while (!q.isEmpty()) {
			Info info = q.poll();
			int rx = info.x;
			int ry = info.y;

			for (int i = 0; i < 4; i++) {
				int nx = rx + dx[i];
				int ny = ry + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C)
					continue;
				if (!visit[nx][ny] && map[nx][ny] != '#') {
					if (map[nx][ny] == 'k') {
						kCnt++;
					}
					else if (map[nx][ny] == 'v') {
						vCnt++;
					}
					visit[nx][ny] = true;
					q.add(new Info(nx, ny));
				}
			}
		}
	}
}
