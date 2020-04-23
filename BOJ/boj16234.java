import java.util.ArrayList;
import java.util.Scanner;

// 인구이동
public class boj16234 {
	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N, L, R;
	static int peopleCnt, country, result = 0;
	static int[][] A;
	static boolean[][] chk;
	static ArrayList<Pos> list;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		L = sc.nextInt();
		R = sc.nextInt();

		A = new int[N][N];
		list = new ArrayList<>();
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = sc.nextInt();
			}
		}
		while (true) {
			boolean flag = false;
			chk = new boolean[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!chk[i][j]) {
						chk[i][j] = true;
						peopleCnt = A[i][j];
						country = 1;
						list.clear();
						list.add(new Pos(i, j));
						
						dfs(i, j);//연합
						if(country == 1)
							continue;
						
						flag = true;
						moveStart();

					}
				}
			}
			if (flag==false) {
				break;
			}
			result++;
		}
		System.out.println(result);
	}
	
	static int dx[] = { 0,-1,0,1 };
	static int dy[] = { 1,0,-1, 0};
	
	private static void dfs(int x, int y) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= N || ny >= N || nx < 0 || ny < 0)
				continue;

			int diff = Math.abs(A[x][y] - A[nx][ny]);

			if (L <= diff && R >= diff && !chk[nx][ny]) {
				peopleCnt += A[nx][ny];
				country++;
				chk[nx][ny] = true;
				list.add(new Pos(nx,ny));
				dfs(nx, ny);
			}
		}
	}
	
	private static void moveStart() {
		for (int i = 0; i < list.size(); i++) {
			int x = list.get(i).x;
			int y = list.get(i).y;
			
			A[x][y] = peopleCnt / country;
		}
	}
}
