import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pos {
	int x, y;

	public Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class boj_4485 {
	static int N;
	static int[][] map, dist;
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int tc = 1;
		while (true) {
			N = Integer.parseInt(br.readLine());
			if (N == 0)
				break;
			map = new int[N][N];
			dist = new int[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dist[i][j] = Integer.MAX_VALUE;
				}
			}

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			bfs();
			StringBuilder sb = new StringBuilder();
			sb.append("Problem "+tc+": ");
			sb.append(dist[N-1][N-1]);
			System.out.println(sb.toString());
			tc++;
		}
	}

	static int ans = 0;

	static void bfs() {
		Queue<Pos> q = new LinkedList<Pos>();
		q.add(new Pos(0, 0));
		dist[0][0] = map[0][0];

		while (!q.isEmpty()) {
			Pos p = q.poll();
			int x = p.x;
			int y = p.y;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					q.add(new Pos(nx, ny));
				}

			}

		}
	}
}
