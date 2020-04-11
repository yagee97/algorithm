import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 점프 게임
public class boj15558 {
	static int N, K;
	static int[][] map;
	static boolean[][] chk;
	static int time = -1;

	// 앞, 뒤
	static int[] dx = { 0, 0 };
	static int[] dy = { 1, -1 };

	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		map = new int[2][N];
		chk = new boolean[2][N];

		st = new StringTokenizer(br.readLine());
		String str = st.nextToken();
		for (int i = 0; i < str.length(); i++) {
			map[0][i] = str.charAt(i) - '0';
		}
		st = new StringTokenizer(br.readLine());
		String str2 = st.nextToken();
		for (int i = 0; i < str2.length(); i++) {
			map[1][i] = str2.charAt(i) - '0';
		}

		// bfs
		if (bfs(0, 0))
			System.out.println("1");
		else
			System.out.println("0");

	}

	private static boolean bfs(int x, int y) {
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(x, y));
		chk[x][y] = true;

		// 1초가 지날때마다 그 칸 삭제. 움직인 다음 삭제
		while (!q.isEmpty()) {
			time++;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				Pos p = q.poll();

				for (int j = 0; j < 3; j++) {
					int nx = 0;
					int ny = 0;
					if (j < 2) {
						nx = p.x + dx[j];
						ny = p.y + dy[j];
					} else {
						nx = p.x ^ 1;
						ny = p.y + K;
					}
					if (ny >= N) {
						return true;
					}
					if (ny <= time)
						continue;
					if (!chk[nx][ny] && map[nx][ny] == 1) {
						chk[nx][ny] = true;
						q.add(new Pos(nx, ny));
					}
				}
			}
		}
		return false;
	}

}
