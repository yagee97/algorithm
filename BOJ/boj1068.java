import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj1068 {
	static int N;
	static ArrayList<Integer>[] list;
	static int cnt = 0;
	static int[] parent;
	static boolean[] check;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		check = new boolean[N];
		parent = new int[N];

		list = new ArrayList[N+1];
		for (int i = 0; i < N; i++) {
			list[i] = new ArrayList<>();
		}

		for (int i = 0; i < N; i++) {
			int num = sc.nextInt();
			// 부모저장
			parent[i] = num;
		}
		int root = 0;
		for (int i = 0; i < N; i++) {
			int v = parent[i];
			if (v == -1) {
				// -1이 뒤에 나올수도 있다.
				root = i;
				continue;
			}
			list[v].add(i);
			list[i].add(v);
		}

		int remove = sc.nextInt();
		//bfs를 두번하면서 한번은 지우는거 한번은 root를 기준으로 leaf노드 탐색
		bfs(remove);
		System.out.println(bfs(root));

	}

	public static int bfs(int num) {
		Queue<Integer> q = new LinkedList<>();
		int cnt = 0;

		if (check[num]) {
			return 0;
		}
		
		q.add(num);
		check[num] = true;
		
		while(!q.isEmpty()) {
			num = q.poll();
			boolean flag = false;
			
			for(int v : list[num]) {
				if (!check[v] && parent[num] != v) {
					// 방문하지 않았고, 부모정점과 현재 정점이 같지 않다면 탐색
					flag = true;
					q.add(v);
					check[v] = true;
				}
				
			}
			// 정점을 기준으로 탐색을 하지 못했을 경우 리프노드.
			if (!flag) {
				cnt++;
			}
		}
		return cnt;
	}
}
