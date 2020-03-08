import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Info {
	int x;
	int y;
	int wall;
	int dis;

	public Info(int x, int y, int wall, int dis) {
		this.x = x;
		this.y = y;
		this.wall = wall;
		this.dis = dis;
	}
}

public class boj_14442 {
	static int N, M, K;
	static int[][] map;
	static boolean[][][] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		visited = new boolean[N][M][K + 1];

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}
		bfs();
		if (ans == Integer.MAX_VALUE)
			System.out.println("-1");
		else
			System.out.println(ans);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int ans = Integer.MAX_VALUE;

	static void bfs() {
		Queue<Info> q = new LinkedList<>();
		q.add(new Info(0, 0, 0, 1));// ½ÃÀÛÁ¡ºÎÅÍ ¼¼¾ßÇÔ
		visited[0][0][0] = true;

		while (!q.isEmpty()) {
			Info info = q.poll();
			int x = info.x;
			int y = info.y;
			int wall = info.wall;
			int dis = info.dis;

			if (x == N - 1 && y == M - 1) {
				ans = Math.min(ans, dis);
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;

				if (!visited[nx][ny][wall]) {
					// »Ñ¼Ì´Âµ¥
					if (wall >= K) {
						// º®ÀÌ¸é ¾ÈµÅ
						if (map[nx][ny] == 1)
							continue;
						else if (map[nx][ny] == 0) {
							visited[nx][ny][wall] = true;
							q.add(new Info(nx, ny, wall, dis + 1));
						}
						// ¾È»Ñ¼Ì´Ù
					} else if (wall < K) {
						if (map[nx][ny] == 1) {
							visited[nx][ny][wall] = true;
							q.add(new Info(nx, ny, wall + 1, dis + 1));
						} else if (map[nx][ny] == 0) {
							visited[nx][ny][wall] = true;
							q.add(new Info(nx, ny, wall, dis + 1));
						}
					}
				}
			}

		}
	}
}
