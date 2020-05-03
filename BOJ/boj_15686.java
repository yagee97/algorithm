import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

// 치킨배달
public class boj_15686 {
	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N, M;
	static int[][] map;
	static boolean[] chk;
	static ArrayList<Pos> house, chicken;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][N];
		house = new ArrayList<>();
		chicken = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1)
					house.add(new Pos(i, j));
				else if (map[i][j] == 2)
					chicken.add(new Pos(i, j));
			}
		}
		chk = new boolean[chicken.size()];
		solve(0, 0);
		System.out.println(ans);

	}
	static int ans = Integer.MAX_VALUE;
	// 치킨집 3개 뽑아서 집이랑 거리 구한다음에 ! 집마다의 치킨거리를 구해서
	// 그거 다 합친거 = 도시의 치킨거리가 최소되는거 찾기
	private static void solve(int idx, int cnt) {
		if (cnt == M) {
			// 최소값 찾기
			int cityDis = 0;
			for (int i = 0; i < house.size(); i++) {
				int hx = house.get(i).x;
				int hy = house.get(i).y;
				int min = Integer.MAX_VALUE;
				for (int j = 0; j < chicken.size(); j++) {
					int dis = 0;
					if (chk[j]) {
						int cx = chicken.get(j).x;
						int cy = chicken.get(j).y;
						dis = calDis(hx, hy, cx, cy);
						if(min > dis)
							min = dis;
					}
				}
				cityDis += min;
			}
			if(ans > cityDis)
				ans = cityDis;
			return;
		}

		for (int i = idx; i < chicken.size(); i++) {
			if (!chk[i]) {
				chk[i] = true; // 치킨집 선택
				solve(i, cnt + 1);
				chk[i] = false;
			}
		}
	}

	private static int calDis(int x1, int y1, int x2, int y2) {
		return Math.abs(x1 - x2) + Math.abs(y1 - y2);
	}
}
