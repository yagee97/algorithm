// 이분그래프
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_1707 {
	static ArrayList<ArrayList<Integer>> list;
	static int[] colors;
	static int V, E;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int K = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());

			list = new ArrayList<>();
			for (int j = 0; j <= V; j++) {
				list.add(new ArrayList<>());
			}

			// 그래프 생성
			for (int j = 0; j < E; j++) {
				st = new StringTokenizer(br.readLine());
				int n1 = Integer.parseInt(st.nextToken());
				int n2 = Integer.parseInt(st.nextToken());
				list.get(n1).add(n2);
				list.get(n2).add(n1);
			}

			// bfs돌리면서 현재 정점과 다음 정점의 색이 다른지 봐야함
			// 모든 정점에 대해
			colors = new int[V + 1];
			boolean flag = true;
			for (int v = 1; v <= V; v++) {
				if (colors[v] == 0) {
					if (!bfs(v)) {
						flag = false;
						break;
					}
				}
			}

			if (flag)
				sb.append("YES\n");
			else
				sb.append("NO\n");
		}
		System.out.println(sb.toString());

	}

	private static boolean bfs(int start) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(start);
		colors[start] = 1;

		while (!q.isEmpty()) {

			int x = q.poll();
			for (int i = 0; i < list.get(x).size(); i++) {
				int y = list.get(x).get(i);// 연결된 모든 정점

				// 이전값과 현재값이 같으면 이분그래프X
				if (colors[y] == colors[x]) {
					return false;
				} else if (colors[y] == 0) {
					colors[y] = colors[x] * -1;
					q.add(y);
				}
			}
		}
		return true;

	}

}
