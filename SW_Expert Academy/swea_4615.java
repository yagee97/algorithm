import java.util.Scanner;

public class swea_4615 {

	static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

	static int N, M;
	static int[][] map;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			N = sc.nextInt();
			M = sc.nextInt();

			map = new int[N + 1][N + 1];
			
			map[N / 2][N / 2 + 1] = 1;
			map[N / 2 + 1][N / 2] = 1;
			map[N / 2][N / 2] = 2;
			map[N / 2 + 1][N / 2 + 1] = 2;

			for (int i = 0; i < M; i++) {
				int y = sc.nextInt();
				int x = sc.nextInt();
				int color = sc.nextInt();

				map[y][x] = color;

				solve(color, y, x);

			}
			int cntB = 0, cntW = 0;
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (map[i][j] == 1)
						cntB++;
					else if (map[i][j] == 2)
						cntW++;
				}
			}
			sb.append("#"+tc+" "+cntB + " "+ cntW);
			System.out.println(sb.toString());
		}
	}

	public static void solve(int color, int y, int x) {
		int ny, nx;
		int oy = y, ox = x;

		for (int i = 0; i < 8; ++i) {
			y = oy;
			x = ox;

			int cnt = 0;
			while (true) {
				ny = y + dy[i];
				nx = x + dx[i];

				if (!isOK(ny, nx))
					break;

				if (map[ny][nx] == 0) {
					break;
				}
				//같은거 나오면 이제 처음 기준 부터 같지 않은 개수 만큼 color 바꾸기
				if (map[ny][nx] == color) {
					y = oy;
					x = ox;
					for (int j = 0; j < cnt; ++j) {
						//지금까지의 방향으로 쭉가기
						ny = y + dy[i];
						nx = x + dx[i];
						map[ny][nx] = color;
						y = ny;
						x = nx;
					}
					break;
				}
				//같지 않으면 이어가면서 좌표 수정해보기
				if (map[ny][nx] != color) {
					cnt++;
					y = ny;
					x = nx;
				}
			}
		}
	}

	public static boolean isOK(int y, int x) {
		return (y > 0 && x > 0 && y <= N && x <= N);
	}

}