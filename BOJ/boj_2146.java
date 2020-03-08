import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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

public class boj_2146 {
	static int N;
	static int[][] map;
	static boolean[][] visit;
	static int idx = 2;
	static int[][] dist;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visit = new boolean[N][N];
		dist = new int[N][N];

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// ¼¶¸¸µé±â
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					dfs(i, j);
					idx++;
				}
			}
		}

		for (int i = 2; i <= idx; i++) {
			bfs(i);
		}
		System.out.println(ans);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void dfs(int x, int y) {
		map[x][y] = idx;
		visit[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (!visit[nx][ny] && map[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}

	static int ans = Integer.MAX_VALUE;

	public static void bfs(int idx) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				dist[i][j] = Integer.MAX_VALUE;
		}

		Queue<Pos> q = new LinkedList<Pos>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == idx) {
					q.add(new Pos(i, j));
					dist[i][j] = 0;
				}
			}
		}

		while (!q.isEmpty()) {
			Pos p = q.poll();
			int x = p.x;
			int y = p.y;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (map[nx][ny] != 0 && map[nx][ny] != idx) {
					if (ans > dist[x][y]) {
						ans = dist[x][y];
					}
					return;
				}
				if (map[nx][ny] == 0 && dist[nx][ny] == Integer.MAX_VALUE) {
					dist[nx][ny] = dist[x][y] + 1;
					q.add(new Pos(nx, ny));
				}
			}
		}
	}
}
