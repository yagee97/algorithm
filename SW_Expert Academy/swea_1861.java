import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
//정사각형 방
public class swea_1861 {
	static int N, cnt = 1;
	static int[][] map;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {

			N = sc.nextInt();
			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int max = 0;
			int ret = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// solve
					cnt = 1;
					solve(i, j);
					if (max < cnt) {
						max = cnt;
						ret = map[i][j];
					}else if(max == cnt) {
						if(ret > map[i][j]) {
							ret = map[i][j];
						}
					}
				}
			}
			System.out.println("#" + tc + " "+ret + " " + max);
		}
	}

	static void solve(int x, int y) {
		int[] dx = { -1, 0, 1, 0 };
		int[] dy = { 0, 1, 0, -1 };
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (map[nx][ny] - map[x][y] == 1) {
				cnt++;
				solve(nx, ny);
			}
		}
	}
}
