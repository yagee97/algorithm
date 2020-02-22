import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//바이러스
public class boj_2606 {
	static int N, M, cnt = 0;
	static ArrayList<Integer> list[];
	static boolean[] check;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		check = new boolean[N+1];
		list = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++)
			list[i] = new ArrayList<>();

		for (int i = 0; i < M; i++) {
			int n1 = sc.nextInt();
			int n2 = sc.nextInt();
			list[n1].add(n2);
			list[n2].add(n1);
		}
		bfs(1);
		System.out.println(cnt);

	}

	static void bfs(int x) {
		Queue<Integer> q = new LinkedList<>();

		q.add(x);
		check[x] = true;

		while (!q.isEmpty()) {
			int rx = q.poll();
			for (int i = 0; i < list[rx].size(); i++) {
				int nx = list[rx].get(i);

				if (nx < 1 || nx > N)
					continue;
				if (!check[nx]) {
					check[nx] = true;
					q.add(nx);
					cnt++;
				}
			}
		}
	}
}
