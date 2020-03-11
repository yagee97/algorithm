import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

//하나로
class Pos implements Comparable<Pos> {
	int x, y;
	double w;

	public Pos(int x, int y, double w) {
		this.x = x;
		this.y = y;
		this.w = w;
	}

	@Override
	public int compareTo(Pos p) {
		if (this.w > p.w)
			return 1;
		else if (this.w < p.w)
			return -1;
		return 0;
	}
}

public class swea_1251 {
	static int N;
	static double E;
	static Pos[] map;
	static int[] parents;

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			map = new Pos[N];
			parents = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				int x = Integer.parseInt(st.nextToken());
				map[i] = new Pos(x, 0, 0);
			}
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int y = Integer.parseInt(st.nextToken());
				map[j].y = y;
			}

			// E
			E = Double.parseDouble(br.readLine());
			ArrayList<Pos> weight = new ArrayList<>();

			// 각 노드끼리의 거리를 계산해서 가중치를 가진 애를 만들어주자
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					weight.add(new Pos(i, j, calWeight(map[i].x, map[i].y, map[j].x, map[j].y)));
				}
			}

			// 가중치 오름차순 정렬
			Collections.sort(weight);

			// parent 생성
			for (int i = 0; i < N; i++) {
				parents[i] = i;
			}

			double ans = 0;
			for (int i = 0; i < weight.size(); i++) {
				// 부모가 같지 않다면 union
				if (find(weight.get(i).x) != find(weight.get(i).y)) {
					union(weight.get(i).x, weight.get(i).y);
					ans = ans + weight.get(i).w;
				}
			}
			System.out.format("#%d %.0f\n", tc, ans);
		}
	}

	static int find(int x) {
		// 자기가 부모면 자기자신 return
		if (x == parents[x])
			return x;
		// 아니면 찾을 때까지 재귀.
		else
			return parents[x] = find(parents[x]);
	}

	static void union(int x, int y) {
		int px = find(x);
		int py = find(y);

		// 부모가 다르다면 연결되어 있지 않은 상태
		if (px != py) {
			parents[py] = px;
		}
	}

	static double calWeight(long x, long y, long dx, long dy) {
		return E * Math.pow(Math.sqrt(Math.pow(dx - x, 2) + Math.pow(dy - y, 2)), 2);
	}
}
