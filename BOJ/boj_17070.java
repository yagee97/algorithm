import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 파이프 옮기기 1
public class boj_17070 {
	static int N;
	static int[][] map;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dfs(0, 1, 0);
		System.out.println(ans);

	}

	static int[] dx = { 0, 1, 1 };
	static int[] dy = { 1, 1, 0 };
	static int ans = 0;

	private static void dfs(int x, int y, int dir) {
		if (x == N-1 && y == N-1) {
			ans++;
			return;
		}
		for (int i = 0; i < 3; i++) {
			if ((dir == 0 && i == 2) || (dir == 2 && i == 0))
				continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (map[nx][ny] == 1)
				continue;
			//대각선으로 움직일꺼면
			if (i == 1) {
				if (map[nx - 1][ny] == 1 || map[nx][ny-1] == 1)
					continue;
			}
			dfs(nx, ny, i);
		}
	}
}
