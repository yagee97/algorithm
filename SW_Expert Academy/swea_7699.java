import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class swea_7699 {
	static class Pos {
		int x, y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int R, C, cnt = 1;
	static int[][] map;
	static boolean[][] visit;
	static int[] freq;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			R = sc.nextInt();
			C = sc.nextInt();
			cnt = 0;
			map = new int[R][C];
			visit = new boolean[R][C];
			freq = new int[101];

			for (int i = 0; i < R; i++) {
				String input = sc.next();
				for (int j = 0; j < input.length(); j++) {
					map[i][j] = input.charAt(j);
				}
			}
			ans = 0;
			dfs(0, 0, 1);
			System.out.println("#" + tc + " " + ans);
		}
	}

	static int ans = 0;
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static void dfs(int x, int y, int cnt) {
		if (ans < cnt)
			ans = cnt;

		// 백트래킹... . ..! 
		freq[map[x][y]]++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (freq[map[nx][ny]] >= 1)
				continue;
			dfs(nx, ny, cnt + 1);
		}
		freq[map[x][y]]--;
	}

}
