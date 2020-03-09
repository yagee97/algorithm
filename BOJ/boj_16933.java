import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Info {
	int x, y, dis, wall, day;

	public Info(int x, int y, int dis, int wall, int day) {
		this.x = x;
		this.y = y;
		this.dis = dis;
		this.wall = wall;
		this.day = day;
	}
}

public class boj_16933 {
	static int N, M, K;
	static int[][] map;
	static boolean[][][] chk;
	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		chk = new boolean[N][M][K + 1];
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

	static int[] dx = { 0, -1, 0, 1 };
	static int[] dy = { 1, 0, -1, 0 };

	public static void bfs() {
		Queue<Info> q = new LinkedList<Info>();
		q.add(new Info(0, 0, 1, 0, 0));// x,y,dis,wall,day
		chk[0][0][0] = true;

		while (!q.isEmpty()) {

			Info info = q.poll();
			int x = info.x;
			int y = info.y;
			int dis = info.dis;
			int wall = info.wall;
			int day = info.day;
			if (x == N - 1 && y == M - 1) {
				ans = dis;
				break;
			}

			// int nDay = day ^ 1;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;

				if (map[nx][ny] == 1) {

					if (wall < K) {
						if (!chk[nx][ny][wall + 1]) {
							// 벽인데 낮이면 뿌시기 가능
							if (day == 0) {
								q.add(new Info(nx, ny, dis + 1, wall + 1, 1));
								chk[nx][ny][wall + 1] = true;
							} else {
								q.add(new Info(x, y, dis + 1, wall, 0));
							}
						}
					}
				} else if (map[nx][ny] == 0) {
					if (!chk[nx][ny][wall]) {
						if (day == 0) {
							q.add(new Info(nx, ny, dis + 1, wall, 1));
							chk[nx][ny][wall] = true;
						} else {
							q.add(new Info(nx, ny, dis + 1, wall, 0));
							chk[nx][ny][wall] = true;
						}
					}
				}
			}
		}

	}
}
